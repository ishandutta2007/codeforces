#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

char A[Maxn], B[Maxn];
int slen;

bool Less(char A[], int i1, int j1, char B[], int i2, int j2)
{
	int len = j1 - i1 + 1;
	for (int i = 0; i < len; i++)
		if (A[i1 + i] != B[i2 + i])
			return A[i1 + i] < B[i2 + i];
	return false;
}

void Fix(char A[], int l, int r)
{
	if ((r - l + 1) % 2) return;
	int m = l + r >> 1;
	Fix(A, l, m); Fix(A, m + 1, r);
	if (Less(A, m + 1, r, A, l, m)) {
		int len = r - m;
		for (int i = 0; i < len; i++)
			swap(A[l + i], A[m + 1 + i]);
	}
}

int main()
{
	scanf("%s", A); scanf("%s", B); slen = strlen(A);
	Fix(A, 0, slen - 1); Fix(B, 0, slen - 1);
	if (Less(A, 0, slen - 1, B, 0, slen - 1) ||
		Less(B, 0, slen - 1, A, 0, slen - 1))
		printf("NO\n");
	else printf("YES\n");
	return 0;
}