#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

map<int,int> UM1, UM2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		int u, v;
		cin >> u >> v;
		UM1[u]++;
		if (!UM1.count(v)) UM1[v] = 0;
		if (v!=u) UM2[v]++;
	}

	int ans = oo;
	for (auto &p : UM1)
	{
//		cout << p.first << " " << p.second << endl;
		if (p.second * 2 >= n){
			cout << 0 << endl;
			return 0;
		}
		else{
			if (!UM2.count(p.first)) continue;
			if ( (UM2[p.first] + p.second) * 2 < n) continue;
			ans = min(ans, (n - 2 * p.second + 1) / 2);
		}
	}
	if (ans >= oo) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}