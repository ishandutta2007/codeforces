#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	const int F = 3;
	vector<int> a(n+F+F, 0);
	for(int i = F; i < n+F; i++) cin >> a[i];
	for(int i = 2; i < F; i++) a[i] = a[F];
	for(int i = n+F; i < n+F+F-2; i++) a[i] = a[n+F-1];
	n = (int)a.size();
	map<int, vector<int> > where;
	for(int i = 0; i < (int)a.size(); i++){
		if(a[i]) where[-a[i]].push_back(i);
	}
	multiset<int> diffs;
	vector<int> ans(n, 0);
	vector<bool> big(n, false);
	vector<int> z(n);
	for(int i = F; i < n-F; i++) z[i-F] = i;
	vector<int> zz(n-1);
	for(int i = 0; i < n-1; i++) zz[i] = i;
	set<int> not_yet(z.begin(), z.end());
	set<int> stuff(zz.begin(), zz.end());
	diffs.insert(1);

	int curval;

	auto set_interval = [&](int s, int e){
		while(true){
			auto r = not_yet.lower_bound(s);
			if(r == not_yet.end() || (*r >= e)) break;
			ans[*r] = -curval;
			not_yet.erase(r);
		}
	};

	auto rem = [&](int idx){
		// remove 00
		auto s = stuff.find(idx);
		int f = *prev(s);
		int g = *s;
		int h = *next(s);

		int rp = big[f];
		int tp = big[h];

		stuff.erase(s);

		if(g-f > 2) diffs.erase(diffs.find(g-f));
		if(h-g > 2) diffs.erase(diffs.find(h-g));
		if(h-f > 2) diffs.insert(h-f);
		if(rp && !tp) set_interval(f, (f + h) / 2 + 1);
		if(!rp && tp) set_interval((f + h + 1) / 2 + 1, h + 2);
		if(rp && tp) set_interval(f, h+2);
	};
	auto ins = [&](int idx){
		// insert 11
		stuff.insert(idx);
		auto s = stuff.find(idx);
		int f = *prev(s);
		int g = *s;
		int h = *next(s);

		int rp = big[f];
		int tp = big[h];

		if(h-f > 2) diffs.erase(diffs.find(h-f));
		if(h-g > 2) diffs.insert(h-g);
		if(g-f > 2) diffs.insert(g-f);
		if(!rp) set_interval((f + g + 1) / 2 + 1, g + 2);
		if(!tp) set_interval(g, (g + h) / 2 + 1);
		if(rp) set_interval(f, g + 2);
		if(tp) set_interval(g, h + 2);
	};

	auto add = [&](int idx) {
		if(!big[idx-1]) rem(idx-1);
		if(!big[idx+1]) rem(idx);
		big[idx] = true;
		if(big[idx-1]) ins(idx-1);
		if(big[idx+1]) ins(idx);
	};

	int c = 0;
	for(auto p : where){
		curval = p.first;
		vector<int> locs = p.second;
		for(int v : locs) add(v);
		c = max(c, (*diffs.rbegin() - 1) / 2);
	}
	cout << c << '\n';
	for(int i = F; i < n-F; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';

	// int on = n-F-F;

	// vector<int> b(on);
	// for(int i = 0; i < on; i++) b[i] = a[i+F];
	// int realc = 0;
	// while(true){
	// 	vector<int> newb = b;
	// 	for(int i = 1; i + 1 < on; i++){
	// 		newb[i] = b[i] + b[i+1] + b[i-1] -
	// 		min(b[i], min(b[i+1], b[i-1])) - max(b[i], max(b[i+1], b[i-1]));
	// 	}
	// 	if(b == newb) break;
	// 	realc++;
	// 	b = newb;
	// }
	// cout << c << ' ' << realc << '\n';
	// for(int i = 0; i < on; i++){
	// 	cout << b[i] << ' ';
	// }
	// cout << '\n';

	// assert(c == realc);
	// for(int i = 0; i < on; i++){
	// 	if(ans[i+F] != b[i]) cerr << i << ' ' << ans[i+F] << ' ' << b[i] << '\n';
	// 	assert(ans[i+F] == b[i]);
	// }
}