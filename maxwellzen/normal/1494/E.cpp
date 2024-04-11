#include <bits/stdc++.h>

using namespace std;

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
int n, m, a, b;
vector<map<int, char>> adj;
char t, c;
set<pi> cycles, ecycles;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    adj.rsz(n+1);
    F0R(i, m) {
        cin >> t;
        if (t=='+') {
            cin >> a >> b >> c;
            adj[a][b]=c;
            if (adj[b].find(a)!=adj[b].end()) {
                cycles.insert(mp(a, b));
                if (adj[a][b]==adj[b][a]) ecycles.insert(mp(a, b));
            }
        } else if (t=='-') {
            cin >> a >> b;
            adj[a].erase(b);
            cycles.erase(mp(a, b));
            cycles.erase(mp(b, a));
            ecycles.erase(mp(a, b));
            ecycles.erase(mp(b, a));
        } else if (t=='?') {
            cin >> a;
            if (a%2==0) {
                if (!ecycles.empty()) cout << "YES\n";
                else cout << "NO\n";
            } else {
                if (!cycles.empty()) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}