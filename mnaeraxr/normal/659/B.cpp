#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100000 + 10;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,string>>> v(m);

	for (int i = 0; i < n; ++i){
		string s;
		int r, val;
		cin >> s >> r >> val;
		v[r - 1].push_back({val, s});
	}

	for (int i = 0; i < m; ++i){
		sort(v[i].begin(), v[i].end());
		int t = (int)v[i].size();


		if (t > 2 && v[i][t - 3].first == v[i][t - 2].first)
			cout << "?" << endl;
		else
			cout << v[i][t - 1].second << " " << v[i][t - 2].second << endl;

	}

	return 0;
}