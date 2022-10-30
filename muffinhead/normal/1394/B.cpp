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
const int MX = 100001; //check the limits, dummy

int ban[10][10][10][10];
int cont[10][10];
int ans = 0;
int pban[10][10];
vi cur;
int K;
int N;
int cc = 0;
void solve(int x, int y) {
    if (x == K) {
        if (N == cc) ans++;
/*        cout << cc << nl;
        F0R(i, K) cout << cur[i] << " ";
        cout << nl;*/
        return;
    }
    int cb = 0;
    F0R(i, sz(cur)) {
        if (ban[x][y][i][cur[i]]) cb++;
    }
    if (cb == 0 && sz(cur) == x && !pban[x][y]) {
        cur.pb(y);
        cc += cont[x][y];
        if (y == x) {
            solve(x+1, 0);
        } else {
            solve(x, y+1);
        }
        cc -= cont[x][y];
        cur.pop_back();
    }
    if ((y < x || sz(cur) > x)) {
        if (y == x) {
            solve(x+1, 0);
        } else {
            solve(x, y+1);
        }
    }

    return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    
    int M; cin >> N >> M >> K;

    vpi vals[N];
    vector<vpi> graph(N);
    F0R(i, M) {
        int A, B, C; cin >> A >> B >> C; A--; B--;
        graph[A].pb({C, B});
    }

    F0R(i, N) sort(all(graph[i]));

    F0R(i, N) {
        F0R(j, sz(graph[i])) {
            vals[graph[i][j].s].pb({sz(graph[i])-1, j});
        }
    }

    F0R(i, N) {
        sort(all(vals[i]));
        F0R(j, sz(vals[i]) - 1) {
            if (vals[i][j] == vals[i][j+1]) {
                pban[vals[i][j].f][vals[i][j].s] = true;
            }
        }
        vals[i].resize(unique(all(vals[i]))-vals[i].begin());

        F0R(j, sz(vals[i])) {
            F0R(k, j) {
                ban[vals[i][j].f][vals[i][j].s][vals[i][k].f][vals[i][k].s]++;
            }
            cont[vals[i][j].f][vals[i][j].s]++;
        }
    }

    solve(0, 0);

    cout << ans << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343