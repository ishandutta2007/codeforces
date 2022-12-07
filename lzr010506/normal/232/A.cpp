#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll lon glong
using namespace std;
const int INF = 1000000007;

int e[505][505];
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
int main()
{
    int a[105], b[105], m, r, t = 3, ans = 0;
    for(int i = 3; i <= 100; i ++)
        a[i] = i * (i - 1) * (i - 2) / 6;
    for(int i = 2; i <= 100; i ++) 
        b[i] = i * (i - 1) / 2;
    scanf("%d", &m);
    vector<int> u;
    for(int i = 3; i <= 100; i ++)
        if(m >= a[i]) t = i;
    for(int i = 0; i < t; i ++)
        for(int j = 0; j < t; j ++)
            e[i][j] = i != j;
    m -= a[ans = t];
    while(m)
    {
        for(int i = r = 2; i <= t; i ++)
            if(m >= b[i]) r = i;
        m -= b[r];
        for(int i = 0; i < r; i ++)
            e[i][ans] = e[ans][i] = 1;
        ans ++;
    }
    printf("%d\n",ans);
    for(int i = 0; i < ans; i ++, puts(""))
        for(int j = 0; j < ans; j ++)
            printf("%d",e[i][j]);
    return 0;
}