#include <bits/stdc++.h>
using namespace std;
#define X 100000
#define N X + 10
#define Y 35
#define M Y + 10
#define lowbit(x) (x & (-x))
#define int long long
//#define int unsigned long long

int n, k;

int _2[M];

int e[N][M], s[N][M], m[N][M];

int t[M];

int ans[N], mn[N];

void file()
{
    freopen("INPUT", "r", stdin);
    freopen("OUTPUT", "w", stdout);
}

int read()
{
    int sum = 0;
    char c = getchar(), flag;
    while(c < '0' || c > '9') flag = c, c = getchar();
    while(c >= '0' && c <= '9') sum = (sum << 1) + (sum << 3) + c - '0', c = getchar();
    if(flag == '-') sum *= -1;
    return sum;
}

void put(int x)
{
    if(x < 0) putchar('-'), x *= -1;
    int sum = 10, len = 1;
    while(sum <= x) sum *= 10, len++;
    while(len--) sum /= 10, putchar(x / sum + '0'), x %= sum;
}

#undef int
#define INT int
INT main()
#undef INT
#define int long long
//#define int unsigned long long
{
    _2[0] = 1;
    n = read(), k = read();
    for(int i = 1; i <= n; i++) e[i][0] = read() + 1;
    for(int i = 1; i <= n; i++)	s[i][0] = m[i][0] = read();
    for(int i = 1; i <= Y; i++) _2[i] = _2[i - 1] * 2;
    for(int p = 1; p <= Y; p++)
        for(int i = 1; i <= n; i++)
            e[i][p] = e[e[i][p - 1]][p - 1],
            s[i][p] = s[i][p - 1] + s[e[i][p - 1]][p - 1],
            m[i][p] = min(m[i][p - 1], m[e[i][p - 1]][p - 1]);
    for(int i = Y; i >= 0; i--) if(k & _2[i]) k -= _2[i], t[++t[0]] = i;
    for(int i = 1, u = 1; i <= n; i++, u = i)
        for(int j = 1; j <= t[0]; j++)
        {
            ans[i] += s[u][t[j]];
            if(j == 1) mn[i] = m[u][t[j]];
            else mn[i] = min(mn[i], m[u][t[j]]);
            u = e[u][t[j]];
//			u = e[u][0];
        }
    for(int i = 1; i <= n; i++) put(ans[i]), putchar(' '), put(mn[i]), puts("");
    return 0;
}