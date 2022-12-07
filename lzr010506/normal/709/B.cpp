#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
int N, A, X, A0, B0, C0, mmx, mmx2, lmn1, lmn2;
int ans = inf;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline int min(int a, int b)
{
	if(a < b) return a;
	return b;
}

int main()
{
	N = read();
	A = read();
	for (int i = 1; i <= N; i ++)
	{
		X = read(), X -= A;
		if (X == 0) A0 ++;
		else
			if (X > 0) B0 ++;
			else if (X < 0) C0 ++;
		if (X > 0)
			if (X >= mmx) mmx2 = mmx, mmx = X;
			else if (X > mmx2) mmx2 = X;
		if (X < 0)
			if (X <= lmn1) lmn2 = lmn1, lmn1 = X;
			else if (X < lmn2) lmn2 = X;
	}
	if(A0 == N - 1) printf("0");
	else 
	{
		ans = min(ans, min(mmx * 2 - lmn2, -lmn2 * 2 + mmx));
		ans = min(ans, min(-lmn1 * 2 + mmx2, mmx2 * 2 - lmn1));
		printf("%d", ans);
	}
	return 0;
}