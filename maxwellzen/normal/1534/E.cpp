#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second

int n, k, ans, hold;
vi dist, par;
queue<int> e, o;
vb vis;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    dist.rsz(n+1, 1e9); par.rsz(n+1); vis.rsz(n+1, false);
    queue<int> q;
    dist[0]=0;
    q.push(0);
    while (! q.empty()) {
        int i = q.front();
        q.pop();
        if (vis[i]) continue;
        vis[i]=true;
        F0R(a, k+1) {
            int b=k-a, nb=i+a-b;
            if (i >= b && n-i >= a && nb>=0 && nb<=n && !vis[nb] && dist[nb]>dist[i]+1) {
                dist[nb]=dist[i]+1;
                par[nb]=a;
                q.push(nb);
            }
        }
    }
    if (dist[n]==1e9) {
        cout << -1 << endl;
        return 0;
    }
    ans=0;
    F0R(i, n) e.push(i+1);
    int i=n;
    while (i > 0) {
        cout << "? ";
        int a=par[i], b=k-a;
        F0R(j, a) {
            int temp = e.front();
            e.pop();
            cout << temp << ' ';
            o.push(temp);
        }
        F0R(j, b) {
            int temp = o.front();
            o.pop();
            cout << temp << ' ';
            e.push(temp);
        }
        i=e.size();
        cout << endl;
        cin >> hold;
        ans ^= hold;
    }
    cout << "! " << ans << endl;
}
// 2 1 7 5 6
// 010 001 111 101 110