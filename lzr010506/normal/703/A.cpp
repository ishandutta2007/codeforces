#include <bits/stdc++.h>
using namespace std;
int A_win, B_win;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	int n = read();
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		x = read();
		y = read();
		if(x < y) B_win ++;
		if(x > y) A_win ++;
	}
	if(B_win > A_win) printf("Chris");
	else if(A_win > B_win) printf("Mishka");
	else if(A_win == B_win) printf("Friendship is magic!^^");
	return 0;
}