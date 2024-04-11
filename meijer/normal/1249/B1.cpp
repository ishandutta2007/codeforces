#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=2e5;
int q, n, p[MX];
int ans[MX];
bitset<MX> visited;
stack<int> used;

void dfs(int u) {
    if(visited[u]) return;
    visited[u] = 1;
    used.push(u);
    dfs(p[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n;
        RE(i,n) cin>>p[i], p[i]--;
        visited.reset();
        RE(i,n) {
            if(!visited[i]) {
                dfs(i);
                int a=used.size();
                while(!used.empty()) {
                    int u = used.top(); used.pop();
                    ans[u] = a;
                }
            }
        }
        RE(i,n)
            cout<<(i==0?"":" ")<<ans[i];
        cout<<endl;
    }
}