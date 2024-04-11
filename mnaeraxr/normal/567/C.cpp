#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	map<int,int64> tot1, tot2;

	cin >> n >> k;

	int64 ans = 0;

	for (int i = 0; i < n; ++i){
		int64 v; cin >> v;

		if (v % k == 0){
			ans += tot2[v / k];
			tot2[v] += tot1[v / k];
		}
		tot1[v] += 1;
	}

	cout << ans << endl;

	return 0;
}