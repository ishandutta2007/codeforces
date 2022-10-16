#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<pair<int,int>,int>> v(m);
	for (int i = 0; i < m; ++i){
		cin >> v[i].first.first >> v[i].first.second;
		v[i].first.second *= -1;
		v[i].second = i;
	}

	vector<pair<int,int>> ans(m);
	sort(v.begin(), v.end());
	vector<int> next(n + 1);
	for (int i = 0; i <= n; ++i)
		next[i] = i + 1;

	int cur = 2;
/*
6 7
1 1
1 1
1 1
1 0
1 0
5 1
10 1
 */
	for (int i = 0, pnt = 2; i < m; ++i){
		if (v[i].first.second == -1){
			if (cur <= n){
				pnt = 2;
				ans[v[i].second] = make_pair(1, cur++);
			}
			else{
				cout << -1 << endl;
				exit(0);
			}
		}
		else{
			while (pnt < cur && next[pnt] == cur){
				++pnt;
			}
			if (pnt == cur){
				cout << -1 << endl;
				exit(0);
			}
			ans[v[i].second] = make_pair(pnt, next[pnt]++);
		}
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i].first << " " << ans[i].second << endl;

	return 0;
}