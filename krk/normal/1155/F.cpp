#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 14;
const int Maxm = 1001;

int bits[1 << Maxn];
int n, m;
int A[Maxm], B[Maxm];
vector <ii> neigh[Maxn];
vector <int> dp[1 << Maxn];
vector <int> seq;
int inseq[Maxn];
vector <int> cur[1 << Maxn][Maxn];

int main()
{
	for (int i = 0; i < 1 << Maxn; i++)
		bits[i] = __builtin_popcount(i);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &A[i], &B[i]);
		A[i]--; B[i]--;
		neigh[A[i]].push_back(ii(B[i], i));
		neigh[B[i]].push_back(ii(A[i], i));
	}
	int all = (1 << n) - 1;
	for (int i = 1; i < all; i++) if (i == 1 || !dp[i].empty()) {
		seq.clear();
		for (int j = 0; j < n; j++) if (!(i & 1 << j)) {
			inseq[j] = seq.size();
			seq.push_back(j);
		}
		for (int j = 0; j < 1 << int(seq.size()); j++)
			for (int k = 0; k < seq.size(); k++)
				cur[j][k].clear();
		for (int j = 0; j < m; j++) {
			int a = (i & 1 << A[j])? 0: A[j];
			int b = (i & 1 << B[j])? 0: B[j];
			if (a == 0 && b == 0 || a != 0 && b != 0) continue;
			if (a != 0) swap(a, b);
			b = inseq[b];
			if (cur[1 << b][b].empty()) cur[1 << b][b].push_back(j);
			else {
				int mask = (i | (1 << seq[b]));
				if (dp[mask].empty() || dp[i].size() + 2 < dp[mask].size()) {
					dp[mask] = dp[i];
					dp[mask].push_back(cur[1 << b][b][0]);
					dp[mask].push_back(j);
				}
			}
		}
		for (int j = 0; j < 1 << int(seq.size()); j++)
			for (int k = 0; k < seq.size(); k++) if (!cur[j][k].empty())
				for (int z = 0; z < neigh[seq[k]].size(); z++) {
					ii u = neigh[seq[k]][z];
					if (i & 1 << u.first) u.first = 0;
					if (u.first == 0) {
						if (cur[j][k].size() >= 2) {
							int mask = 0;
							for (int c = 0; c < seq.size(); c++) if (j & 1 << c)
								mask |= 1 << seq[c];
							if (dp[i | mask].empty() || dp[i].size() + cur[j][k].size() + 1 < dp[i | mask].size()) {
								dp[i | mask] = dp[i];
								for (int c = 0; c < cur[j][k].size(); c++)
									dp[i | mask].push_back(cur[j][k][c]);
								dp[i | mask].push_back(u.second);
							}
						}
						continue;
					}
					u.first = inseq[u.first];
					if (!(j & 1 << u.first)) {
						int nj = (j | (1 << u.first));
						if (cur[nj][u.first].empty() || cur[j][k].size() + 1 < cur[nj][u.first].size()) {
							cur[nj][u.first] = cur[j][k];
							cur[nj][u.first].push_back(u.second);
						}
					}
				}
	}
	printf("%d\n", int(dp[all].size()));
	for (int i = 0; i < dp[all].size(); i++) {
		int ind = dp[all][i];
		printf("%d %d\n", A[ind] + 1, B[ind] + 1);
	}
    return 0;
}