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
    vpi ans;
    for (int i = 0; (1 << i) < N; i++) {
        for (int j = 0; j + (1 << (i+1)) <= N; j+=(1<<(i+1))) {
            F0R(k, (1 << i)) {
                ans.pb({j+k+1, j+k+1+(1<<i)});
            }
        }
        
    }

    vi bits;
    F0Rd(i, 20) {
        if (N & (1 << i)) {
            bits.pb(i);
        }
    }
    if (sz(bits) >= 2) {
    vi dblo[sz(bits)];
    int cur = 0;
    F0R(i, sz(bits)) {
        F0R(j, (1 << bits[i])) {
            dblo[i].pb(cur);
            cur ++;
        }
    }

    vi blo1 = dblo[0], blo2 = dblo[1];
    FOR(i, 2, sz(bits)) {
        vi blo3 = dblo[i];
        while (sz(blo3) < (1 << (bits[0] - 1))) {
            if (sz(blo2) & sz(blo3)) {
                F0R(i, sz(blo3)) {
                    ans.pb({blo3[i]+1, blo2[sz(blo2)-1-i]+1});
                }
                int X = sz(blo3);
                F0R(i, X) {
                    blo3.pb(blo2[sz(blo2)-1]);
                    blo2.pop_back();
                }
            } else {
                F0R(i, sz(blo3)) {
                    ans.pb({blo3[i]+1, blo1[sz(blo1)-1-i]+1});
                }
                int X = sz(blo3);
                F0R(i, X) {
                    blo3.pb(blo1[sz(blo1)-1]);
                    blo1.pop_back();
                }
            }
//            cout << "CUR " << sz(blo1) << " " << sz(blo2) << " " << sz(blo3) << nl;
        }
        if (sz(blo2) > 0) {

            F0R(i, sz(blo3)) {
                ans.pb({blo2[i]+1, blo3[i]+1});
                blo2.pb(blo3[i]);
            }
            swap(blo2, blo1);
        } else {
            F0R(i, sz(blo3)) {
                ans.pb({blo1[sz(blo1)-1] + 1, blo3[i] + 1});
                blo2.pb(blo3[i]);
                blo2.pb(blo1[sz(blo1)-1]);
                blo1.pop_back();
            }
            swap(blo2, blo1);
        }
//        cout << "DONE" << sz(blo1) << " " << sz(blo2) << nl;
/*        trav(a, blo1) {
            cout << a << " ";
        }
        cout << nl;
        trav(b, blo2) {
            cout << b << " ";
        }
        cout << nl;
        break;*/
    }

    }
    cout << sz(ans) << nl;
    trav(a, ans) {
        cout << a.f << " " << a.s << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343