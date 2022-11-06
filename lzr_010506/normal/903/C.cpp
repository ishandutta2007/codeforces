#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define ll long long
#define N 200010
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
int n, x;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

map<int, int> Mp;

int main()
{
    n = read();
    rep(i, 1, n) Mp[read()] ++;
    int ans = 0;
    while (!Mp.empty())
    {
        ans ++;
        for (map<int, int>::iterator it = Mp.begin(); it != Mp.end(); it ++) it -> Y --;
        for (map<int, int>::iterator it = Mp.begin(); it != Mp.end(); )
        {
            map<int, int>::iterator t = it;
            ++ it;
            if (t -> Y <= 0) Mp.erase(t -> X);
        }
    }
    printf("%d\n", ans);
    return 0;
}