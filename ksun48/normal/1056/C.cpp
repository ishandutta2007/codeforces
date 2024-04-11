#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> p(2*n);
	for(int i = 0; i < 2*n; i++){
		cin >> p[i];
	}
	vector<int> a(m), b(m);
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		if(p[a[i]] < p[b[i]]){
			swap(a[i], b[i]);
		}
	}
	vector<int> used(2*n, 0);
	int t;
	cin >> t;
	if(t == 1){
		for(int turn = 0; turn < n; turn++){
			int done = 0;
			for(int i = 0; i < m; i++){
				if(used[a[i]]){
					assert(used[b[i]]);
				} else {
					if(!done){
						done = 1;
						cout << a[i] + 1 << '\n';
						used[a[i]] = 1;
						fflush(stdout);
						int r;
						cin >> r;
						r--;
						used[r] = 1;
						assert(r == b[i]);
					}
				}
			}
			if(!done){
				int best = -1;
				for(int i = 0; i < 2*n; i++){
					if(used[i]) continue;
					if(best == -1 || p[i] > p[best]) best = i;
				}
				cout << best + 1 << '\n';
				used[best] = 1;
				fflush(stdout);
				int r;
				cin >> r;
				r--;
				used[r] = 1;
				done = 1;
			}
		}
	} else {
		for(int turn = 0; turn < n; turn++){
			int r;
			cin >> r;
			r--;
			used[r] = 1;
			int done = 0;
			for(int i = 0; i < m; i++){
				if(!done){
					if(a[i] == r && !used[b[i]]){
						cout << b[i] + 1 << '\n';
						used[b[i]] = 1;
						fflush(stdout);
						done = 1;
					} else if(b[i] == r && !used[a[i]]){
						cout << a[i] + 1 << '\n';
						used[a[i]] = 1;
						fflush(stdout);
						done = 1;
					}
				}
			}
			for(int i = 0; i < m; i++){
				if(used[a[i]]){
					assert(used[b[i]]);
				} else {
					if(!done){
						done = 1;
						cout << a[i] + 1 << '\n';
						used[a[i]] = 1;
						fflush(stdout);
					}
				}
			}
			if(!done){
				int best = -1;
				for(int i = 0; i < 2*n; i++){
					if(used[i]) continue;
					if(best == -1 || p[i] > p[best]) best = i;
				}
				cout << best + 1 << '\n';
				used[best] = 1;
				fflush(stdout);
				done = 1;
			}
		}
	}
}