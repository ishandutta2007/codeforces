#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 6006;

int T;
int n;
int L[Maxn], R[Maxn];
vector <int> un;
vector <int> byL[Maxn];
int dp[Maxn][Maxn];
int my[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		un.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &L[i], &R[i]);
			un.push_back(L[i]);
			un.push_back(R[i]);
		}
		L[n] = 0; R[n] = 1000000000;
		n++;
		sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
		for (int i = 0; i <= un.size(); i++)
			byL[i].clear();
		vector <ii> V;
		for (int i = 0; i < n; i++) {
			L[i] = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
			R[i] = lower_bound(un.begin(), un.end(), R[i]) - un.begin();
			byL[L[i]].push_back(i);
			V.push_back(ii(R[i] - L[i], i));
		}
		sort(V.begin(), V.end());
		for (int i = 0; i < V.size(); i++) {
			int ind = V[i].second;
			for (int j = L[ind]; j <= R[ind] + 1; j++)
				dp[ind][j] = 0;
			for (int j = L[ind]; j <= R[ind]; j++) {
				dp[ind][j + 1] = max(dp[ind][j + 1], dp[ind][j]);
				for (int l = 0; l < byL[j].size(); l++) {
					int ind2 = byL[j][l];
					if (ind2 == ind) continue;
					if (R[ind2] <= R[ind])
						dp[ind][R[ind2] + 1] = max(dp[ind][R[ind2] + 1], dp[ind][j] + my[ind2] + 1);
				}
			}
			my[ind] = dp[ind][R[ind] + 1];
		}
		printf("%d\n", my[n - 1]);
	}
    return 0;
}