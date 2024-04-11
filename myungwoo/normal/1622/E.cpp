#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int N, M;
	cin >> N >> M;
	vector<int> X(N);
	vector<vector<bool>> sheet(N, vector<bool>(M+1));
	for (int i=0;i<N;i++) cin >> X[i];
	for (int i=0;i<N;i++){
		string s; cin >> s;
		for (int j=1;j<=M;j++) sheet[i][j] = s[j-1] == '1';
	}
	int ans = -1;
	vector<pair<int, int>> perm;
	for (int msk=0;msk<(1<<N);msk++){
		vector<bool> neg(N);
		int base = 0;
		for (int i=0;i<N;i++){
			if (msk>>i&1) neg[i] = 1, base += X[i];
			else base -= X[i];
		}
		vector<pair<int, int>> arr;
		for (int i=1;i<=M;i++){
			int v = 0;
			for (int j=0;j<N;j++) if (sheet[j][i]){
				if (neg[j]) v--;
				else v++;
			}
			arr.emplace_back(v, i);
		}
		sort(arr.begin(), arr.end());
		for (int i=0;i<M;i++) base += arr[i].first*(i+1);
		if (ans < base) ans = base, perm = arr;
	}
	vector<int> score(M+1);
	for (int i=0;i<M;i++) score[perm[i].second] = i+1;
	for (int i=1;i<=M;i++) cout << score[i] << ' ';
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}