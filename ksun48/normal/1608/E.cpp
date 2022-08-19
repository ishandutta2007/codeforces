#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> x(n), y(n), c(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> c[i];
		c[i]--;
	}
	int k = 0;
	for(int it = 0; it < 4; it++){
		vector<int> xs(n), ys(n);
		for(int i = 0; i < n; i++) xs[i] = ys[i] = i;
		sort(xs.begin(), xs.end(), [&](int r, int s) { return x[r] < x[s]; });
		sort(ys.begin(), ys.end(), [&](int r, int s) { return y[r] < y[s]; });
		for(int cc = 0; cc < 3; cc++){
			int s = 0;
			int e = n+1;
			while(s + 1 < e){
				int m = (s + e) / 2;
				int xmax = -2e9;
				int nr = 0;
				for(int i = 0; i < n; i++){
					if(c[xs[i]] == cc){
						nr++;
						xmax = x[xs[i]];
						if(nr == m){
							break;
						}
					}
				}
				if(nr < m){
					e = m;
					continue;
				}
				int c1 = (cc + 1) % 3;
				int c2 = (cc + 2) % 3;
				vector<pair<vector<int>, vector<int> > > cands;
				cands.push_back({xs, x});
				cands.push_back({ys, y});
				bool works = false;
				for(auto [ord, coord] : cands){
					int lc1 = 0;
					int rc1 = 0;
					int lc2 = 0;
					int rc2 = 0;
					for(int a : ord){
						if(x[a] > xmax){
							if(c[a] == c1){
								rc1++;
							} else if(c[a] == c2){
								rc2++;
							}
						}
					}
					int i = 0;
					while(i < (int)ord.size()){
						int j = i;
						while(j < (int)ord.size() && coord[ord[i]] == coord[ord[j]]){
							j++;
						}
						for(int z = i; z < j; z++){
							int a = ord[z];
							if(x[a] > xmax){
								if(c[a] == c1){
									rc1--;
									lc1++;
								}
								if(c[a] == c2){
									rc2--;
									lc2++;
								}
							}
						}
						if(lc1 >= m && rc2 >= m) works = true;
						if(rc1 >= m && lc2 >= m) works = true;
						i = j;
					}
				}
				if(works){
					s = m;
				} else {
					e = m;
				}
			}
			k = max(k, s);
		}
		for(int i = 0; i < n; i++){
			x[i] = -x[i];
			swap(x[i], y[i]);
		}
	}
	cout << 3 * k << '\n';
}