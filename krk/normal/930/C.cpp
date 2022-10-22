#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, m;
int delt[Maxn];
int L[Maxn], R[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int l, r; scanf("%d %d", &l, &r);
		delt[l]++; delt[r + 1]--;
	}
	int cur = 0;
	vector <int> seq;
	for (int i = 1; i <= m; i++) {
		cur += delt[i]; delt[i] = cur;
		int ind = upper_bound(seq.begin(), seq.end(), cur) - seq.begin();
		if (ind == seq.size()) seq.push_back(cur);
		else seq[ind] = cur;
		L[i] = seq.size();
	}
	seq.clear();
	for (int i = m; i >= 1; i--) {
		int ind = upper_bound(seq.begin(), seq.end(), delt[i]) - seq.begin();
		if (ind == seq.size()) seq.push_back(delt[i]);
		else seq[ind] = delt[i];
		R[i] = seq.size();
	}
	res = max(L[m], R[1]);
	for (int i = 1; i + 1 <= m; i++)
		res = max(res, L[i] + R[i + 1]);
	printf("%d\n", res);
	return 0;
}