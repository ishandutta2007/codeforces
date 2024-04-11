#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n , m;
	cin >> n >> m;
	vector <multiset <int> > arr(n + 1);
	for(int i = 0 ;i  < m;i++) {
		int v , u;
		cin >> v >> u;
		arr[v].insert(u);
	}
	for (int i = 1; i <= n;i++) {
		multiset <int> kuda;
		vector <multiset <int> > state = arr;
		int start = i , tmp = m , sum = 0;
		while(tmp) {
			if(arr[start].size() > 0) {
				int maxi = -1e9 , ind = 0;
				for (auto to : arr[start]) {
					if(to < start) {
						maxi = max(n - start + to , maxi);
						if(maxi == n - start + to) {
							ind = to;
						}
					} else {
						if(maxi < to - start) {
							ind = to;
							maxi = to-start;
						}
					}
				}
				multiset <int>::iterator it = arr[start].find(ind);
				kuda.insert(*(it));
				arr[start].erase(it);
			}
			sum++;
			if(kuda.find(start) != kuda.end()) {
				//cout << start << ' ' << kuda.count(start) << endl;
				tmp -= kuda.count(start);
				kuda.erase(start);
			}
			if(start == n) {
				start = 1;
			} else {
				start++;
			}
		}
		arr = state;
		cout << sum - 1 << ' ';
	}
}