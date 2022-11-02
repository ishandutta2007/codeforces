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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    ll H[N]; F0R(i, N) cin >> H[i];

    ll S = H[0], Z = -1;
    FOR(i, 1, N) {
        if (Z != -1) {
            ll val = S + i - 2;
            ll mov = min((ll) i - 1 - Z, H[i] - val - 1);
            Z += mov; H[i] -= mov;
            if (Z == i-1) {
                Z = -1;
            }
        }
//        cout << S << " " << Z << " start" << nl;
        if (Z == -1) {
            ll mov = (H[i] - S - i + 1) / (i+1);
            S += mov; H[i] -= mov * i;
//            cout << S << " " << Z << " " << H[i] << " after" << nl;
            if (H[i] - (S + i - 1) >= 2) {
                S++; H[i] --; Z = 0;
                ll val = S + i - 2;
                mov = H[i] - val - 1;
                Z += mov; H[i] -= mov;
            }
        }
        if (Z == -1 && S+i-1 == H[i]) {
            Z = i-1;
        }
//        cout << S << " " << Z << nl;
    }

    F0R(i, N) {
        cout << S << " ";
        if (i != Z) S++;
    }
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343