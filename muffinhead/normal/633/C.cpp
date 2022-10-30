#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

struct hsh	{
	ll base, p1, p2;
	
	ll val1, val2;
	deque<ll> vals;
	
	ll inv1, inv2;
	
	ll modExp(ll power, ll prime) {
		if (power == 0) {
			return 1;
		} else {
			ll cur = modExp(power / 2, prime); cur = cur * cur; cur = cur % prime;
			if (power % 2 == 1) cur = cur * base;
			cur = cur % prime;
			return cur;
		}
	}
	
	hsh() {
	}
	
	hsh(ll b, ll x, ll y) {
		base = b;
		p1 = x;
		p2 = y;
		val1 = 0;
		val2 = 0;
		
		inv2 = modExp(p2-2, p2);
		inv1 = modExp(p1-2, p1);
	}
	
	hsh(ll b) {
		p1 = 1000000007;
		p2 = 1000000009;
		base = b;
		val1 = 0;
		val2 = 0;
		
		inv2 = modExp(p2-2, p2);
		inv1 = modExp(p1-2, p1);
	}
	
	hsh(ll b, string S) {
		p1 = 1000000007;
		p2 = 1000000009;
		base = b;
		val1 = 0;
		val2 = 0;
		
		inv2 = modExp(p2-2, p2);
		inv1 = modExp(p1-2, p1);
		F0R(i, sz(S)) {
			push_back(S[i] - 'a');
		}
	}
	
	void push_back(ll v) {
		val1 *= base;
		val1 %= p1;
		val1 += v;
		val1 %= p1;
		val2 *= base;
		val2 %= p2;
		val2 += v;
		val2 %= p2;
		
		vals.push_back(v);
	}
	
	void pop_back() {
		ll cur = vals.back();
		vals.pop_back();
		
		val1 += p1 - cur; val1 %= p1;
		val1 = val1 * inv1; val1 %= p1;
		
		val2 += p2 - cur; val2 %= p2;
		val2 = val2 * inv2; val2 %= p2;
	}
	
	void push_front(ll v) {
		val1 += v * modExp(sz(vals), p1);
		val1 %= p1;
		
		val2 += v * modExp(sz(vals), p2);
		val2 %= p2;
		
		vals.push_front(v);
	}
	
	void pop_front() {
		ll v = vals.front();
		vals.pop_front();
		ll sub1 = (v * modExp(sz(vals), p1)) % p1;
		val1 += p1 - sub1; val1 %= p1;
		
		ll sub2 = (v * modExp(sz(vals), p2)) % p2;
		val2 += p2 - sub2; val2 %= p2;
		
	}
	
	bool operator==(const hsh &v) const { 
		return (val1 == v.val1 && val2 == v.val2 && sz(vals) == sz(v.vals)); 
	}
	
	bool operator<(const hsh &v) const {
		if (val1 == v.val1 && val2 == v.val2) {
			return sz(vals) < sz(v.vals);
		} else if (val1 == v.val1) {
			return val2 < v.val2;
		} 
		return val1 < v.val1;
	}
	
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);	
	
	uniform_int_distribution<> dist(1000, MOD - 2);
	ll base = dist(rng);
	
	int N; cin >> N;
	
	string S; cin >> S;
	
	
	
	
	int M; cin >> M;
	
	map<hsh, string> data;
	
	F0R(i, M) {
		string val; cin >> val;
		
		string cur = val;
		F0R(j, sz(cur)) cur[j] = tolower(cur[j]);
		
		reverse(all(cur));
		
		data.insert(mp(hsh(base, cur), val));
	}
	
	bool dp[N+1];
	hsh last[N+1];
	
	F0R(i, N+1) dp[i] = false;
	dp[0] = true;
	

	
	F0R(i, N) {
		if (!dp[i]) continue;
		hsh hash(base);
		F0R(j, 1001) {
			if (i+j >= N) break;
			hash.push_back(S[i+j]-'a');
			if (!dp[i+j+1] && data.count(hash)) {
				dp[i+j+1] = true;
				last[i+j+1] = hash;
			}
		}
	}
	
	vector<string> ans;
	
	int cur = N;
	while (cur > 0) {
		ans.pb(data[last[cur]]);
		cur -= sz(data[last[cur]]);
	}
	
	reverse(all(ans));
	
	F0R(i, sz(ans)) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}