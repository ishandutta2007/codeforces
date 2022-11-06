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
int a, b, c;
int vis[100010];
int main() 
{
    a = read();
    b = read();
    c = read();
    int r = a;
    int cnt = 0;
    while (!vis[r]) 
    {
        cnt ++;
        vis[r] = 1;
        int s = r * 10 / b;
        if (s == c) 
        {
            printf("%d\n", cnt);
            return 0;
        }
        r = r * 10 % b;
    }
    printf("-1\n");
    return 0;
}