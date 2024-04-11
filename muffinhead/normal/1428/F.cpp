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
    string S; cin >> S;
    ll score[N];
    score[N-1] = S[N-1] - '0';
    vector<pair<ll, pair<int, bool> > > ev;
    F0Rd(i, N-1) {
        if (S[i] == '1') {
            score[i] = score[i+1] + 1;
        } else {
            score[i] = 0;
        }
    }

    F0Rd(i, N) {
        if (S[i] == '1' && (i == 0 || S[i-1] == '0')) {
            ev.pb({score[i], {i, true}});
        } else {
            ev.pb({score[i], {i, false}});
        }
    }
    sort(all(ev)); reverse(all(ev));
    int nc[N]; 
    set<int> in;
    F0R(i, N) {
        int x = ev[i].s.f;
        if (in.lb(x) == in.end()) {
            nc[x] = N;
        } else {
            nc[x] = *in.lb(x);
        }
        if (ev[i].s.s) {
            in.ins(ev[i].s.f);
        }
    }


    ll ans[N];

    F0Rd(i, N) {
        if (S[i] == '0') {
            if (i == N-1) {
                ans[i] = 0;
            } else {
                ans[i] = ans[i+1];
            }
        } else {
            if (nc[i] == N) {
                ll cnt = N - score[i] - i;
                ans[i] = (score[i] * (score[i] + 1)) / 2 + cnt * score[i];
            } else {
                ll pos = nc[i] + score[i];
                ll cnt = pos - score[i] - i;
//                ans[i] = (score[i] * (score[i] + 1)) / 2 + cnt * score[i] + ans[nc[i]] - (score[nc[i]] * (score[nc[i]] + 1)) / 2;
                ans[i] = cnt * score[i] + ans[nc[i]];
            }
        }
    }

/*    F0R(i, N) {
        cout << i << " " << nc[i] << " " << score[i] << " " << ans[i] << nl;
    }*/



    ll res = 0; F0R(i, N) res += ans[i];
    cout << res << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343