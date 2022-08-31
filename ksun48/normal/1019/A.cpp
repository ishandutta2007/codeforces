#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, m;
	cin >> n >> m;
	vector<LL> p(n);
	vector<LL> c(n);
	vector<vector<LL> > d(m);
	for(LL i = 0; i < n; i++){
		cin >> p[i] >> c[i];
		p[i]--;
		d[p[i]].push_back(c[i]);
	}
	for(LL j = 0; j < m; j++){
		sort(d[j].begin(), d[j].end());
	}
	LL best = 1000000000000000LL;
	for(LL i = 1; i <= n; i++){
		LL ans = 0;
		vector<LL> unused;
		LL numvotes = d[0].size();
		for(LL j = 1; j < m; j++){
			LL q = i-1;
			for(LL k = 0; k < d[j].size(); k++){
				if(k + q >= d[j].size()){
					unused.push_back(d[j][k]);
				} else {
					ans += d[j][k];
					numvotes++;
				}
			}
		}
		sort(unused.begin(), unused.end());
		for(LL a : unused){
			if(numvotes < i){
				numvotes++;
				ans += a;
			}
		}
		best = min(best, ans);
	}
	cout << best << endl;
}