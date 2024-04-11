#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> A, B, C;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t; scanf("%d", &t);
		if (t == 1) A.push_back(i);
		else if (t == 2) B.push_back(i);
		else C.push_back(i);
	}
	int mn = min(min(A.size(), B.size()), C.size());
	printf("%d\n", mn);
	for (int i = 0; i < mn; i++)
		printf("%d %d %d\n", A[i], B[i], C[i]);
	return 0;
}