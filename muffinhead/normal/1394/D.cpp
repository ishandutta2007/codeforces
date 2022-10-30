#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200001; //check the limits, dummy
int N;
ll H[MX], T[MX];
ll dp[3][MX]; //0: edge going up, 1: edge going down, 2: no edge
vector<vi> graph(MX);
int t[3][2] = {{1, 0}, {0, 1}, {0, 0}};

void dfs(int v, int p) {
    int l = 0, h = 0, e = 0;
    vl ev;
    ll sum = 0;
    trav(a, graph[v]) {
        if (a == p) continue;
        dfs(a, v);
        if (H[a] > H[v]) {
            h++;
            sum += dp[1][a]; 
        } else if (H[a] < H[v]) {
            l++;
            sum += dp[0][a];
        } else {
//            cout << "TEST 3" << nl;
            e++;
            ev.pb(dp[1][a] - dp[0][a]);
            sum += dp[0][a];
        }
    }
    sort(all(ev));
    F0R(i, 3) dp[i][v] = 1e12;
    F0R(X, 3) {
        h += t[X][0];
        l += t[X][1];

        //Do stuff
        F0R(i, sz(ev) + 1) {
            int cl = l + sz(ev) - i;
            int ch = h + i;
            ckmin(dp[X][v], sum + T[v] * max(cl, ch));

            if (i < sz(ev)) {
                sum += ev[i];
            }
        }
        F0R(i, sz(ev)) sum -= ev[i];


        h -= t[X][0];
        l -= t[X][1];
    }
    if (p != -1) {
        if (H[v] > H[p]) {
            dp[0][v] = 1e12;
        } else if (H[v] < H[p]) {
            dp[1][v] = 1e12;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    cin >> N;
    F0R(i, N) cin >> T[i];
    F0R(i, N) cin >> H[i];

    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y);
        graph[Y].pb(X);
    }

    dfs(0, -1);

    cout << dp[2][0] << nl;

/*    F0R(i, N) {
        cout << i << " ";
        F0R(j, 3) {
            cout << dp[j][i] << " ";
        }
        cout << nl;
    }*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343