#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; ll T; cin >> N >> T;

    ll data[N]; int maxim[N];
    F0R(i, N) cin >> data[i];
    F0R(i, N) cin >> maxim[i];

    int maxSF = 0;
    F0R(i, N) {
    	if (maxim[i] < maxSF || maxim[i] <= i) {
    		cout << "No" << endl; return 0;
    	}
    	maxSF = maxim[i];
    }

    ll minima[N], maxima[N];
    F0R(i, N) {
    	minima[i] = T + data[i];
    	maxima[i] = 4000000000000000000;
    }

    int push[N]; F0R(i, N) push[i] = 0;
    F0R(i, N) {
    	if (maxim[i] > i+1) {
    		push[i+1]++;
    		if (maxim[i] < N) push[maxim[i]]--;
    	}
    	if (maxim[i] < N) {
    		maxima[maxim[i]-1] = data[maxim[i]] - 1 + T;
    	}
    }

    int pref = 0;
    F0R(i, N) {
    	pref += push[i];
    	if (pref > 0) {
    		minima[i-1] = T + data[i];
    	}
    }

    
    vl answers;
    ll curMax = 1;
    F0R(i, N) {
    	ll ans = minima[i];

    	if (ans < curMax) {
    		ans = curMax;
    	}
    	answers.pb(ans);
    	if (ans > maxima[i]) {
    		cout << "No" << endl;
    		return 0;
    	}
    	curMax = ans + 1;
    }
    cout << "Yes" << endl;
    F0R(i, N) {
    	cout << answers[i] << " ";
    }

    cout << endl;
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343