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
int t, n, m, k, typ, y, d;
ll x;

void solve() {
    cin >> n >> m;
//    set<int> consider;
//    FOR(i, 1, m+1) consider.insert(i);
    vector<bool> reachable(m+1, false);
    vi ans(m+1, -1), need(m+1, 0);
    ans[0]=0;
    reachable[0]=true;
    FOR(turn, 1, n+1) {
        cin >> typ >> x >> y;
        fill(need.begin(), need.end(), 0);
        if (typ==1) {
            d = (int) ((x+99999)/100000);
            F0R(i, m-d+1) {
                if (reachable[i] && (! reachable[i+d]) && need[i]<y) {
                    reachable[i+d]=true;
                    ans[i+d]=turn;
                    need[i+d]=need[i]+1;
                }
            }
        } else {
            F0R(i, m+1) {
                ll nex = ((x*((ll)i)+99999)/100000);
                if (nex>m) continue;
                int next = (int) nex;
                if (reachable[i] && (! reachable[next]) && need[i]<y) {
                    reachable[next]=true;
                    ans[next]=turn;
                    need[next]=need[i]+1;
                }
            }
        }
//        FOR(i, 1, m+1) cout << (reachable[i]?1:0) <<  ' ';
//        cout << '\n';
//        FOR(i, 1, m+1) cout << ans[i] << ' ';
//        cout << '\n';
    }
    FOR(i, 1, m+1) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}