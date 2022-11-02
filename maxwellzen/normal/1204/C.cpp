#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
int n, m;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int dist[n][n];
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (i==j) dist[i][j]=0;
            else if (s[j]=='1') dist[i][j]=1;
            else dist[i][j]=1000;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    cin >> m;
    int p[m];
    for (int i = 0; i < m; i++) {cin >> p[i]; p[i]--;}
    vector<int> ans;
    ans.push_back(p[0]);
    int s = 0;
    for (int i = 1; i < m; i++) {
        if (dist[p[s]][p[i]]<i-s) {
            ans.push_back(p[i-1]);
            s=i-1;
        }
    }
    ans.push_back(p[m-1]);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i+1 << ' ';
    cout << '\n';
}