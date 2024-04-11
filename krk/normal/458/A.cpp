#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

char a[Maxn], b[Maxn];
int alen, blen, mx;
int A[Maxn], B[Maxn];

void Fix(int ind)
{
	int mn = min(A[ind], B[ind]);
	A[ind] -= mn; B[ind] -= mn;
}

int Comp()
{
	for (int i = 0; i < mx; i++)
		if (A[i] != B[i])
			if (A[i] == 2) return 1;
			else if (B[i] == 2) return -1;
			else if (i + 1 == mx || i + 2 == mx) return A[i] < B[i]? -1: A[i] == B[i]? 0: 1;
			else if (A[i] > B[i])
					if (B[i + 1]) { A[i + 2]++; Fix(i + 2); i++; }
					else return 1;
				 else if (A[i + 1]) { B[i + 2]++; Fix(i + 2); i++; }
				 	  else return -1;
	return 0;
}

int main()
{
	scanf("%s", a); alen = strlen(a);
	scanf("%s", b); blen = strlen(b);
	mx = max(alen, blen);
	for (int i = 1; i <= alen; i++)
		A[mx - i] = a[alen - i] - '0';
	for (int i = 1; i <= blen; i++)
		B[mx - i] = b[blen - i] - '0';
	for (int i = 0; i < mx; i++)
		if (A[i] == 1 && B[i] == 1) A[i] = B[i] = 0;
	int res = Comp();
	if (res < 0) printf("<\n");
	else if (res == 0) printf("=\n");
	else if (res > 0) printf(">\n");
	return 0;
}