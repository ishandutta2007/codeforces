#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n >> d;
	vector<pii> pep(n);

	for (int i = 0; i < n; ++i)
		cin >> pep[i].first >> pep[i].second;

	sort(pep.begin(), pep.end());

	int64 ans = 0;
	int64 cur = 0;

	for (int i = 0, j = 0; i < n; ++i){
		cur += pep[i].second;

		while (pep[i].first - pep[j].first >= d){
			cur -= pep[j].second;
			++j;
		}
		ans = max(ans, cur);
	}

	cout << ans << endl;

	return 0;
}