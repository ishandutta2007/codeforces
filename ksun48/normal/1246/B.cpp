#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	map<vector<pair<int,int> >, int> f;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		vector<pair<int,int> > v, w;
		int a;
		cin >> a;
		for(int p = 2; p * p <= a; p++){
			int r = 0;
			while(a % p == 0){
				r++;
				a /= p;
			}
			r %= k;
			if(r > 0){
				v.push_back({p, r});
				w.push_back({p, k-r});
			}
		}
		if(a > 1){
			v.push_back({a, 1});
			if(k > 1) w.push_back({a, k - 1});
		}
		ans += f[w];
		f[v]++;
	}
	cout << ans << '\n';
}