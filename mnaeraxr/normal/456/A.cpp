#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<pair<int,int>> V(n);
	for (int i = 0; i < n; ++i)
		cin >> V[i].first >> V[i].second;
	sort(V.begin(), V.end());
	bool ok = true;
	for (int i = 1; i < n && ok; ++i)
		if (V[i - 1].first < V[i].first &&
			V[i - 1].second > V[i].second) ok = false;
	if (ok) cout << "Poor Alex" << endl;
	else cout << "Happy Alex" << endl;
}