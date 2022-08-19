#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int d = -1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		if(a[i] == 0) d = i;
	}
	// add d to end;
	vector<int> arr;
	for(int i = d+1; i < n; i++){
		arr.push_back(a[i]);
	}
	for(int i = 0; i < d; i++){
		arr.push_back(a[i]);
	}
	assert((int)arr.size() == n-1);
	vector<int> pos(n, -1);
	for(int i = 0; i < n-1; i++){
		pos[arr[i]] = i;
	}
	auto val = [&](int s, int e) -> int {
		set<pair<int,int> > f;
		f.insert({-1, 0});
		f.insert({n, 0});
		vector<pair<int,int> > nums;
		int maxd = 0;
		for(int i = 0; i < n; i++){
			if(s <= pos[i] && pos[i] < e){
				auto g = f.lower_bound({pos[i], 0});
				int val = max((*g).second, (*prev(g)).second) + 1;
				maxd = max(maxd, val);
				f.insert({pos[i], val});
			}
		}
		return maxd;
	};
	int s = 0;
	int e = n-1;
	while(s + 1 < e){
		int m = (s + e) / 2;
		int vl = val(0, m);
		int vr = val(m, n-1);
		if(vl > vr){
			e = m;
		} else {
			s = m;
		}
	}
	int sans = 1 + max(val(0, s), val(s, n-1));
	int eans = 1 + max(val(0, e), val(e, n-1));
	if(sans <= eans){
		cout << sans << " " << (1 + s + d) % n << '\n';
	} else {
		cout << eans << " " << (1 + e + d) % n << '\n';		
	}
}