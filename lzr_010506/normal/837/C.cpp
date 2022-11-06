#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;
int a, b, n, l, r, ans;
int x[200], y[200], i, j;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline bool check(int i, int j) 
{
    l = max(x[i], x[j]);
    r = y[i] + y[j];
    if ((l <= a && r <= b) || (l <= b && r <= a)) return 1;
    l = max(x[i], y[j]);
    r = y[i] + x[j];
    if ((l <= a && r <= b) || (l <= b && r <= a)) return 1;
    l = max(y[i], x[j]);
    r = x[i] + y[j];
    if ((l <= a && r <= b) || (l <= b && r <= a)) return 1;
    l = max(y[i], y[j]);
    r = x[i] + x[j];
    if ((l <= a && r <= b) || (l <= b && r <= a)) return 1;
    return 0;
}

int main() 
{
    n = read();
    a = read();
    b = read();
    rep(i, 1, n) x[i] = read(), y[i] = read();
    ans = 0;
    rep(i, 1, n)
    	rep(j, i + 1, n)
            if (check(i, j))
                ans = max(ans, x[i] * y[i] + x[j] * y[j]);
        
    printf("%d\n", ans);
    return 0;
}