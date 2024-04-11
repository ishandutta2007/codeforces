#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	vector<int> loc(n);
	for(int i = 0; i < n; i++){
		loc[a[i]] = i;
	}
	vector<int> next_more(n), next_less(n), prev_more(n), prev_less(n);
	vector<int> next_bad(n, n), prev_bad(n, -1);
	{
		set<int> idx;
		idx.insert(-1);
		idx.insert(n);
		set<int> bad_inc;
		bad_inc.insert(-1);
		bad_inc.insert(n);
		set<int> bad_dec;
		bad_dec.insert(-1);
		bad_dec.insert(n);
		for(int i = 0; i < n; i++){
			int v = loc[i];
			idx.insert(v);
			auto lv = idx.find(v);
			int f = *prev(lv);
			int h = *next(lv);
			int g = *lv;
			if(f >= 0 && h < n && a[f] > a[h]) bad_inc.erase(f);
			if(f >= 0 && h < n && a[f] < a[h]) bad_dec.erase(h);
			prev_bad[v] = max(prev_bad[v], *prev(bad_inc.lower_bound(v)));
			next_bad[v] = min(next_bad[v], *bad_dec.upper_bound(v));
			if(f >= 0 && g < n && a[f] > a[g]) bad_inc.insert(f);
			if(g >= 0 && h < n && a[g] > a[h]) bad_inc.insert(g);
			if(f >= 0 && g < n && a[f] < a[g]) bad_dec.insert(g);
			if(g >= 0 && h < n && a[g] < a[h]) bad_dec.insert(h);
			prev_less[v] = f;
			next_less[v] = h;
		}
	}
	{
		set<int> idx;
		idx.insert(-1);
		idx.insert(n);
		set<int> bad_inc;
		bad_inc.insert(-1);
		bad_inc.insert(n);
		set<int> bad_dec;
		bad_dec.insert(-1);
		bad_dec.insert(n);
		for(int i = n-1; i >= 0; i--){
			int v = loc[i];
			idx.insert(v);
			auto lv = idx.find(v);
			int f = *prev(lv);
			int h = *next(lv);
			int g = *lv;
			if(f >= 0 && h < n && a[f] > a[h]) bad_inc.erase(h);
			if(f >= 0 && h < n && a[f] < a[h]) bad_dec.erase(f);
			prev_bad[v] = max(prev_bad[v], *prev(bad_dec.lower_bound(v)));
			next_bad[v] = min(next_bad[v], *bad_inc.upper_bound(v));
			if(f >= 0 && g < n && a[f] > a[g]) bad_inc.insert(g);
			if(g >= 0 && h < n && a[g] > a[h]) bad_inc.insert(h);
			if(f >= 0 && g < n && a[f] < a[g]) bad_dec.insert(f);
			if(g >= 0 && h < n && a[g] < a[h]) bad_dec.insert(g);
			prev_more[v] = f;
			next_more[v] = h;
		}
	}
	for(int i = 0; i < n; i++){
		if(i + 1 < n) assert(prev_bad[i] <= prev_bad[i+1]);
		if(i + 1 < n) assert(next_bad[i] <= next_bad[i+1]);
	}
	auto check = [&](int l, int r) -> bool {
		int s = l;
		int e = n;
		while(s + 1 < e){
			int m = (s + e) / 2;
			if(prev_bad[m] >= l){
				e = m;
			} else {
				s = m;
			}
		}
		int x = s;
		if(x >= r) return true;
		int y = x + 1;
		if(next_bad[y] <= r) return false;
		if(prev_less[x] >= l && next_more[y] <= r && a[prev_less[x]] > a[next_more[y]]) return false;
		if(prev_more[x] >= l && next_less[y] <= r && a[prev_more[x]] < a[next_less[y]]) return false;
		return true;
	};
	int cr = 0;
	int64_t ans = 0;
	for(int l = 0; l < n; l++){
		cr = max(cr, l);
		while(cr < n && check(l, cr)) cr++;
		ans += cr - l;
	}
	cout << ans << '\n';
}