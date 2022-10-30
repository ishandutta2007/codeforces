# include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

set<int> L, R;

vector<int> vec;

int main() {
	int n, val; 
	char op[12];
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%s%d", op, &val);
		if(op[1] == 'C') {
			if(!L.empty() && *L.rbegin() > val) {
				puts("0"); return 0;
			}
			if(!R.empty() && *R.begin() < val) {
				puts("0"); return 0;
			}
			if(L.count(val)) L.erase(val);
			if(R.count(val)) R.erase(val);
			for(auto v: vec) {
				if(v < val) L.insert(v);
				if(v > val) R.insert(v);
				if(v == val) ans += 1;
			}
			vec.clear();
		} else {
			if(!L.empty() && *L.rbegin() > val) {
				L.insert(val);
			} else if(!R.empty() && *R.begin() < val) {
				R.insert(val);
			} else {
				vec.push_back(val);
			}
		}
	}
	int res = vec.size() + 1;
	for(int i = 0; i < ans; ++i) {
		res = res << 1;
		if (res >= mod) res -= mod;
	}
	printf("%d\n", res);
	return 0;
}