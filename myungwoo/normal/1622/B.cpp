#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int N;
	cin >> N;
	vector<int> P(N+1), Q(N+1);
	vector<bool> liked(N+1);
	for (int i=1;i<=N;i++) cin >> P[i];
	{
		string tmp; cin >> tmp;
		for (int i=1;i<=N;i++) liked[i] = tmp[i-1] == '1';
	}

	vector<pair<int, int>> arr;
	for (int i=1;i<=N;i++) arr.emplace_back(P[i], i);
	sort(arr.begin(), arr.end());
	int p = 1, q = 1;
	for (int i=1;i<=N;i++) if (!liked[i]) q++;
	for (auto [_, i]: arr){
		if (liked[i]) Q[i] = q++;
		else Q[i] = p++;
	}
	for (int i=1;i<=N;i++) cout << Q[i] << ' ';
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}