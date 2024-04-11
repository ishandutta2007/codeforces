#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int L[Maxn], R[Maxn];
vector <int> seq1, seq2;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		seq1.clear(); seq2.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &L[i], &R[i]);
			seq1.push_back(R[i]);
			seq2.push_back(L[i]);
		}
		sort(seq1.begin(), seq1.end());
		sort(seq2.begin(), seq2.end());
		int res = n;
		for (int i = 0; i < n; i++) {
			int ind = lower_bound(seq1.begin(), seq1.end(), L[i]) - seq1.begin();
			int ind2 = upper_bound(seq2.begin(), seq2.end(), R[i]) - seq2.begin();
			res = min(res, ind + int(seq2.size()) - ind2);
		}
		printf("%d\n", res);
	}
    return 0;
}