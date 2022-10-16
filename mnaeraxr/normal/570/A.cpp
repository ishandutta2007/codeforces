#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < m; ++i){
		int idx = 0, vv = -1;
		for (int j = 1; j <= n; ++j){
			int c; cin >> c;
			if (c > vv){
				vv = c;
				idx = j;
			}
		}
		v[idx - 1]++;
	}

	int idx = -1, vv = -1;
	for (int i = 0; i < n; ++i){
		if (v[i] > vv){
			vv = v[i];
			idx = i + 1;
		}
	}

	cout << idx << endl;
}