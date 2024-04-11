# include <bits/stdc++.h>
using namespace std;

const int maxn = 150000+10;
int n;

int main() {
	scanf("%d", &n);
	int x, y; 
	scanf("%d%d", &x, &y);
	vector<int> res_list;
	for(long long i = 2; i * i <= x; ++i) if(x % i == 0) {
		res_list.push_back(i);
		while(x % i == 0) x /= i;
	}
	if(x > 1) res_list.push_back(x);
	for(auto v: res_list) {
		while(y % v == 0) y /= v;
	}
	for(long long i = 2; i * i <= y; ++i) if(y % i == 0) {
		res_list.push_back(i);
		while(y % i == 0) y /= i;
	}
	if(y > 1) res_list.push_back(y);
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		const vector<int> new_res(res_list);
		res_list.clear();
		for(auto v: new_res) if(x % v == 0 || y % v == 0) {
			res_list.push_back(v);
		}
	}
	if(res_list.empty()) {
		puts("-1");
	} else {
		printf("%d\n", *res_list.begin());
	}
}