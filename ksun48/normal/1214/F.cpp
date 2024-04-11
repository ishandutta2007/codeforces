#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll m;
	ll n;
	cin >> m >> n;
	vector<ll> _a(n);
	vector<ll> _b(n);
	vector<ll> a(n); vector<ll> b(n);
	map<ll, set<ll> > ax, bx;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		a[i] *= 2;
		_a[i] = a[i];
		ax[_a[i]].insert(i);
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		b[i]--;
		b[i] *= 2;
		_b[i] = b[i];
		bx[_b[i]].insert(i);
	}
	m *= 2;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<pair<ll, ll> > events;
	for(int i = 0; i < n; i++){
		events.push_back({a[i], 0});
		events.push_back({b[i], 1});
		events.push_back({a[i]+m, 0});
		events.push_back({b[i]+m, 1});
	}
	sort(events.begin(), events.end());

	ll pos_sum = 0;
	ll neg_sum = 0;
	ll cur_ans = 0;

	map<ll, ll> freq;
	ll counter = 0;

	ll cpsum = 0;
	for(int i = 0; i < 2*n; i++){
		if(events[i].second == 0){
			cpsum += 1;
		} else {
			cpsum -= 1;
		}
		ll diff = events[i+1].first - events[i].first;
		freq[cpsum] += diff;
		if(cpsum > 0){
			pos_sum += diff;
		}
		if(cpsum < 0){
			neg_sum += diff;
		}
		cur_ans += abs(cpsum) * diff;
	}
	assert(cpsum == 0);
	ll ans = 2e18;
	ll ans_idx = -1;
	for(int i = 0; i < 2*n; i++){
		if(cur_ans < ans){
			ans = cur_ans;
			ans_idx = i;
		}
		if(events[i].second == 0){
			// subtract one from all
			neg_sum += freq[counter];
			cur_ans += neg_sum;
			counter += 1;
			cur_ans -= pos_sum;
			pos_sum -= freq[counter];
		} else {
			// add one from all
			pos_sum += freq[counter];
			cur_ans += pos_sum;
			counter -= 1;
			cur_ans -= neg_sum;
			neg_sum -= freq[counter];
		}
	}
	cout << ans / 2 << '\n';
	vector<ll> as, bs;
	for(ll _i = ans_idx; _i < ans_idx + 2*n; _i++){
		ll i = _i % (2 * n);
		if(events[i].second == 0){
			ll r = events[i].first % m;
			as.push_back(*ax[r].begin());
			ax[r].erase(ax[r].begin());
		} else {
			ll r = events[i].first % m;
			bs.push_back(*bx[r].begin());
			bx[r].erase(bx[r].begin());
		}
	}
	vector<ll> pp(n, -1);
	for(ll i = 0; i < n; i++){
		pp[as[i]] = bs[i];
	}
	for(ll i = 0; i < n; i++){
		cout << pp[i] + 1 << ' ';
	}
	cout << '\n';
}