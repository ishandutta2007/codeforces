#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int na, nb;
	vector<pair<int,int>> t;
	cin >> na;
	for (int i = 0; i < na; ++i){
		int v; cin >> v;
		t.push_back(make_pair(v,1));
	}
	cin >> nb;
	for (int i = 0; i < nb; ++i){
		int v; cin >> v;
		t.push_back(make_pair(v,2));
	}
	sort(t.begin(), t.end());

	pair<int,pair<int,int>> ans;
	int a2 = 0, a3 = na;
	int b2 = 0, b3 = nb;
	ans = make_pair(3 * a3 - 3 * b3, make_pair(3 * a3, 3 * b3));

	for (int i = 0, j = 0; i < na + nb; i = j){
		int cur = t[i].first;
		for (j = i; j < na + nb && t[j].first == cur; ++j){
			if (t[j].second == 1){
				a2++;
				a3--;				
			}
			else{
				b2++;
				b3--;
			}
		}
		int va = 2 * a2 + 3 * a3;
		int vb = 2 * b2 + 3 * b3;
		pair<int,pair<int,int>> ttt = make_pair(va - vb, make_pair(va, vb));
		ans = max(ans, ttt);
	}

	cout << ans.second.first << ":" << ans.second.second << endl;


	return 0;
}