#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 20;

int n, m;
ii A[Maxn], B[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &A[i].first, &A[i].second);
		if (A[i].first > A[i].second)
			swap(A[i].first, A[i].second); 
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &B[i].first, &B[i].second);
		if (B[i].first > B[i].second)
			swap(B[i].first, B[i].second); 
	}
	for (int i = 0; i < n; i++) {
		bool fir = false, sec = false;
		for (int j = 0; j < m; j++)
			if (A[i] != B[j]) {
				fir |= (A[i].first == B[j].first || A[i].first == B[j].second);
				sec |= (A[i].second == B[j].first || A[i].second == B[j].second);
			}
		if (fir && sec) { printf("-1\n"); return 0; }
	}
	for (int i = 0; i < m; i++) {
		bool fir = false, sec = false;
		for (int j = 0; j < n; j++)
			if (B[i] != A[j]) {
				fir |= (B[i].first == A[j].first || B[i].first == A[j].second);
				sec |= (B[i].second == A[j].first || B[i].second == A[j].second);
			}
		if (fir && sec) { printf("-1\n"); return 0; }
	}
	set <int> nums;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (A[i] != B[j]) {
				if (A[i].first == B[j].first || A[i].first == B[j].second)
					nums.insert(A[i].first);
				if (A[i].second == B[j].first || A[i].second == B[j].second)
					nums.insert(A[i].second);
			}
	if (nums.size() == 1)
		printf("%d\n", *nums.begin());
	else printf("0\n");
	return 0;
}