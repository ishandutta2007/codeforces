#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> B(n);
	for(int& x : B){
		cin >> x;
	}

	auto ncr = [&](int a, int b) -> int {
		return (a & b) == b;
	};
	vector<vector<int> > f(n+3, vector<int>(5, -1));
	auto get = [&](int nleft, int yes) -> int {
		if(f[nleft][yes] == -1){
			int x = 0;
			int need = (k+2) - yes;
			need = max(need, 0);
			for(int z = need; z <= nleft; z++){
				x ^= ncr(nleft, z);
			}
			f[nleft][yes] = x;
		}
		return f[nleft][yes];
	};

	int R = 1 << 20;
	vector<int> ans(R, 0);
	for(int i = 0; i < n; i++){
		int64_t cur = B[i];
		for(int j = i; j < n; j++){
			if(j > i){
				if(B[j] >= 20) break;
				cur = (cur << B[j]);
				if(cur >= R) break;
			}
			int no = j-i;
			int yes = 2 + int(i > 0) + int(j < n-1);
			int tot = n+1;
			int nleft = tot - yes - no;
			ans[cur] ^= get(nleft, yes);
		}
	}
	while(ans.size() > 1 && ans.back() == 0) ans.pop_back();
	reverse(ans.begin(), ans.end());
	for(int x : ans){
		cout << x;
	}
	cout << '\n';
}