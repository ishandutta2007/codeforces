#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
struct el {
	ll d;
	ll m;

	bool operator< (el& other) {
		return (other.d == 0 && d != 0) || (m * other.d < other.m * d);
	}
};

const ll N = 1<<17;
const ll inf = 1e9 + 7;
ll ini[N];
ll man[N];
ll reg[N];

ll tag[2*N];
ll min_prev[2*N];
ll max_prev[2*N];

ll base[2*N];
vector<ll> prefix_sum[2*N];
vector<ll> suffix_sum[2*N];
vector<el> els[2*N];
bool fix[2*N];
bool subfix[2*N];
ll h = 1;

void build(ll i, bool re) {
	if (fix[i]) return;
	if (re) {
		fix[i] = true;
		subfix[i] = true;
	}

	if (i < h) {
		build(2*i, re);
		build(2*i+1, re);

		base[i] = base[2*i] + base[2*i+1];
		els[i].clear();
		merge(els[2*i].begin(), els[2*i].end(), els[2*i+1].begin(), els[2*i+1].end(), back_inserter(els[i]));
		ll s = els[i].size();

		prefix_sum[i].resize(s + 1);
		prefix_sum[i][0] = 0;
		for (ll j = 0; j < s; ++j) {
			prefix_sum[i][j+1] = prefix_sum[i][j] + els[i][j].m;
		}

		suffix_sum[i].resize(s + 1);
		suffix_sum[i][s] = 0;
		for (ll j = s-1; j >= 0; --j) {
			suffix_sum[i][j] = suffix_sum[i][j+1] + els[i][j].d;
		}
	} else {
		base[i] = (re ? 0 : ini[i-h]);
		els[i].resize(1);
		els[i][0].d = reg[i-h];
		els[i][0].m = man[i-h] - base[i];
		prefix_sum[i] = {0, man[i-h] - base[i]};
		suffix_sum[i] = {reg[i-h], 0};
	}
	/*
	if ((i == 5) && (!re)) {
		cout << "i=5:\n";
		cout << base[i] << '\n';
		for (auto it : els[i]) cout << it.d << ' ' << it.m << "  "; cout << '\n';
		for (auto it : prefix_sum[i]) cout << it << ' '; cout << '\n';
		for (auto it : suffix_sum[i]) cout << it << ' '; cout << '\n';
	}
	*/	
}

ll get(ll i, ll t) {
	// cout << "get " << i << ' ' << t << '\n';
	ll low = 0;
	ll high = els[i].size();
	while(low != high) {
		ll mid = (low + high) >> 1;
		if ((els[i][mid].d != 0) && (els[i][mid].m <= els[i][mid].d * t)) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	ll res = base[i] + prefix_sum[i][low] + t * suffix_sum[i][low];
	build(i, 1);
	return res;
}

void upd(ll i) {
	min_prev[i] = min(min_prev[2*i], min_prev[2*i+1]);
	max_prev[i] = max(max_prev[2*i], max_prev[2*i+1]);
	if (fix[2*i] && fix[2*i+1]) build(i, 1);
	if (subfix[2*i] || subfix[2*i+1]) subfix[i] = true;
}

void push(ll i) {
	if (tag[i] == -inf) return;
	min_prev[i] = tag[i];
	max_prev[i] = tag[i];
	if (i < h) {
		tag[2*i] = tag[i];
		tag[2*i+1] = tag[i];
	}
	tag[i] = -inf;
}

ll calc(ll a, ll b, ll t, ll ia = 0, ll ib = h-1, ll i = 1) {
	push(i);
	if (b < ia || ib < a) return 0;
	if (a <= ia && ib <= b && min_prev[i] == max_prev[i] && fix[i] == subfix[i]) {
		ll res = get(i, t-min_prev[i]);
		// cout << "calc " << ia << ' ' << ib << ' ' << t << ' ' << min_prev[i] << ' ' << res << '\n';
		tag[i] = t; push(i);
		return res;
	}
	ll mid = (ia + ib) >> 1;
	ll res = 0;
	res += calc(a, b, t, ia, mid, 2*i);
	res += calc(a, b, t, mid+1, ib, 2*i+1);
	upd(i);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin >> n;

	while(h < n) h <<= 1;
	for (ll i = 0; i < n; ++i) {
		cin >> ini[i] >> man[i] >> reg[i];
	}
	build(1, 0);
	
	ll m;
	cin >> m;
	while(m--) {
		ll t, a, b;
		cin >> t >> a >> b;
		--a; --b;
		ll res = calc(a,b,t);
		cout << res << '\n';
	}
	return 0;
}