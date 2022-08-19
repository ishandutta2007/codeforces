#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> left_less(n), left_more(n), right_less(n), right_more(n);
	map<int, vector<int> > inc, dec;
	for(int i = 0; i < n; i++){
		inc[a[i]].push_back(i);
		dec[-a[i]].push_back(i);
	}
	{
		set<int> r;
		r.insert(-1);
		r.insert(n);
		for(auto f : inc){
			for(int x : f.second){
				auto z = r.lower_bound(x);
				right_less[x] = *z;
				left_less[x] = *prev(z);
			}
			for(int x : f.second) r.insert(x);
		}
	}
	{
		set<int> r;
		r.insert(-1);
		r.insert(n);
		for(auto f : dec){
			for(int x : f.second){
				auto z = r.lower_bound(x);
				right_more[x] = *z;
				left_more[x] = *prev(z);
			}
			for(int x : f.second) r.insert(x);
		}
	}
	vector<pair<int, vector<int> > > closest3(n, {n, {}}), closest4(n, {n, {}});
	for(int i = 0; i < n; i++){
		if(left_less[i] >= 0 && right_less[i] < n){
			closest3[left_less[i]] = min(closest3[left_less[i]], {right_less[i], {left_less[i], i, right_less[i]}});
		}
		if(left_more[i] >= 0 && right_more[i] < n){
			closest3[left_more[i]] = min(closest3[left_more[i]], {right_more[i], {left_more[i], i, right_more[i]}});
		}
	}
	vector<vector<int> > ins_where(n);
	for(int i = 0; i < n; i++){
		int f = min(left_less[i], left_more[i]);
		if(f == -1) continue;
		ins_where[f].push_back(i);		
	}
	set<int> ok;
	ok.insert(n);
	for(int i = n-1; i >= 0; i--){
		for(int x : ins_where[i]){
			ok.insert(x);
		}
		int f = max(right_less[i], right_more[i]);
		int g = *ok.lower_bound(f);
		if(g == n) continue;
		int v = right_less[i];
		int w = right_more[i];
		if(a[v] > a[left_less[g]]) v = left_less[g];
		if(a[w] < a[left_more[g]]) w = left_more[g];
		closest4[i] = {g, {i, v, w, g}};
	}
	for(int i = n-1; i > 0; i--){
		closest3[i-1] = min(closest3[i-1], closest3[i]);
		closest4[i-1] = min(closest4[i-1], closest4[i]);
	}

	for(int _ = 0; _ < q; _++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		vector<int> ans;
		if(closest4[l].first <= r){
			ans = closest4[l].second;
		} else if(closest3[l].first <= r){
			ans = closest3[l].second;
		}
		cout << ans.size() << '\n';
		sort(ans.begin(), ans.end());
		for(int x : ans){
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
}