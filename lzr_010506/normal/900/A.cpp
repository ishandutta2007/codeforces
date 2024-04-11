#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int u, v;
int n;
int main() 
{
	n = read();
	rep(i, 1, n)
	{
        int x = read(), y = read();
        if (x > 0) v ++;
        else u ++;
    }
    if (v <= 1 || u <= 1) puts("Yes");
    else puts("No\n");
    return 0;
}