#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int T;
int n;
int a[Maxn];
int L[Maxn], R[Maxn];
int bad[Maxn];
map <int, int> delt[Maxn];
map <int, int> M;
int ones;

void Update(int x, int val)
{
	ones -= M[x] == 1;
	M[x] += val;
	ones += M[x] == 1;
	if (M[x] == 0) M.erase(x);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		vector <int> S;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			while (!S.empty() && a[S.back()] > a[i]) {
				R[S.back()] = i - 1;
				S.pop_back();
			}
			if (!S.empty()) L[i] = S.back() + 1;
			else L[i] = 0;
			S.push_back(i);
		}
		while (!S.empty()) {
			R[S.back()] = n - 1;
			S.pop_back();
		}
		for (int i = 0; i <= n + 1; i++) {
			bad[i] = 0;
			delt[i].clear();
		}
		for (int i = 0; i < n; i++) {
			if (L[i] < i && i < R[i]) {
				delt[1][a[i]]++;
				delt[2][a[i]]--;
				bad[2]++;
				bad[R[i] - L[i] + 1]--;
				delt[R[i] - L[i] + 1][a[i]]++;
				delt[R[i] - L[i] + 2][a[i]]--;
			} else {
				delt[1][a[i]]++;
				delt[R[i] - L[i] + 2][a[i]]--;
			}
		}
		int cur = 0;
		M.clear(); ones = 0;
		for (int i = 1; i <= n; i++) {
			for (auto it: delt[i])
				Update(it.first, it.second);
			cur += bad[i];
			int res = cur == 0 && ones == n - i + 1 && M.rbegin()->first <= n - i + 1;
			printf("%d", res);
		}
		printf("\n");
	}
    return 0;
}