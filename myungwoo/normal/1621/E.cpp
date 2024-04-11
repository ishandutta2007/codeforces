#include <bits/stdc++.h>
using namespace std;

using lld = long long;

void solve()
{
	int N, M;
	cin >> N >> M;

	int A[N+1];
	for (int i=1;i<=N;i++) cin >> A[i];
	sort(A+1, A+N+1, greater<int>());

	int B[M+1];
	vector<int> students[M+1];
	for (int i=1;i<=M;i++){
		int n; cin >> n; students[i].resize(n);
		for (int& v: students[i]) cin >> v;

		B[i] = (accumulate(students[i].begin(), students[i].end(), 0LL)-1)/n+1;
	}
	sort(B+1, B+M+1, greater<int>());

	int K[3][M+1]; memset(K, 0, sizeof(K));
	for (int i=1;i<=M;i++){
		if (i > 1) K[0][i] = A[i-1] >= B[i];
		K[1][i] = A[i] >= B[i];
		if (i < M) K[2][i] = A[i+1] >= B[i];
		for (int j=0;j<3;j++) K[j][i] += K[j][i-1];
	}

	for (int i=1;i<=M;i++){
		lld sum = accumulate(students[i].begin(), students[i].end(), 0LL);
		int n = students[i].size();
		int old_bound = (sum-1)/n+1;
		int from = lower_bound(B+1, B+M+1, old_bound, greater<int>()) - B;
		for (int v: students[i]){
			int new_bound = (sum-v-1)/(n-1)+1;

			int to = lower_bound(B+1, B+M+1, new_bound, greater<int>()) - B;
			bool possible = 1;
			if (from < to) to--;
			if (K[1][min(from, to)-1] != min(from, to)-1) possible = 0;
			if (K[1][M]-K[1][max(from, to)] != M-max(from, to)) possible = 0;
			if (A[to] < new_bound) possible = 0;
			if (from < to){
				if (K[0][to]-K[0][from] != to-from) possible = 0;
			}else{
				if (K[2][from-1]-K[2][to-1] != from-to) possible = 0;
			}
			cout << possible;
		}
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}