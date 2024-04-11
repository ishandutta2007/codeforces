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

const ll MOD = 1000000007;
const ll INF = 1e18;
const int MX = 500001; //check the limits, dummy

ll mul(ll A, ll B) {
	return (A*B) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); //CHANGE MX BEFORE SUBMITTING!!!!!!!!
    
    ll* pows = new ll[MX]; pows[0] = 1;
    FOR(i, 1, MX) {
    	pows[i] = pows[i-1] * 2; pows[i] = pows[i] % MOD;
    }

    int N, M; ll K; cin >> N >> M >> K;
    ll data[N]; F0R(i, N) cin >> data[i];

    ll ans = pows[K] * pows[N]; ans = ans % MOD;
    map<ll, vpi> graphs;
    F0R(i, M) {
    	int A, B; cin >> A >> B; A--; B--;
    	ll X = data[A] ^ data[B];
    	if (graphs.count(X)) {
    		graphs[X].pb(mp(A, B));
    	} else {
    		vpi blank; blank.pb(mp(A, B));
    		graphs.insert(mp(X, blank));
    	}
    }
    for (auto it = graphs.begin(); it != graphs.end(); it++) {
    	vpi data = it->s;
    	map<int, int> compress;
    	int nxt = 0;
    	F0R(i, sz(data)) {
    		if (!compress.count(data[i].f)) {
    			compress.insert(mp(data[i].f, nxt)); nxt++;
    		}
    		if (!compress.count(data[i].s)) {
    			compress.insert(mp(data[i].s, nxt)); nxt++;
    		}
    	}
    	int count = N - nxt;
    	vector<vi> graph(nxt);
    	F0R(i, sz(data)) {
    		int A = compress[data[i].f], B = compress[data[i].s];
    		graph[A].pb(B); graph[B].pb(A);
    	}


    	int nxtComp = 0;
    	int comp[nxt]; F0R(i, nxt) comp[i] = -1;
    	F0R(i, nxt) {
    		if (comp[i] != -1) { /*cout << "Already considered " << i << ", skipping" << endl;*/ continue; }
    		comp[i] = nxtComp;
    		//cout << "Starting " << nxtComp << " with " << i << endl;
    		queue<int> q; q.push(i);

    		while (!q.empty()) {
    			int cur = q.front(); q.pop();
    			F0R(j, sz(graph[cur])) {
    				int nxt = graph[cur][j];
    				//cout << "At " << cur << ", considering " << nxt << endl;
    				if (comp[nxt] == -1) {
    					//cout << "Valid" << endl;
    					comp[nxt] = nxtComp;
    					q.push(nxt);
    				}
    			}
    		}
    		nxtComp++;
    	}
    	count += nxtComp;

    	ans -= pows[N]; ans += pows[count]; ans += MOD; ans = ans % MOD;

    }

    cout << ans << endl;
	    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343