/*****************************************
Author: lizi
Email: zyli@smail.nju.edu.cn
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 200005;
int p[maxn], pp[maxn], a[maxn], f[20][maxn], pos[maxn], st[20][maxn], lo[maxn], oo;
int n, m, q;

int cal(int len, int u)
{
    len --;
    for(int i = oo; i >= 0; -- i) if((len >> i) & 1) u = f[i][u];
    return u;
}

int find(int l, int r)
{
    int t = lo[r - l + 1];
    return max(st[t][l], st[t][r - (1 << t) + 1]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    oo = 1; while((1 << oo) < n) ++ oo;
    for(int i = 1; i <= n; ++ i) scanf("%d", &p[i]), pp[p[i]] = i;
    for(int i = 1; i <= m; ++ i) scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++ i)
    {
        int x = pp[a[i]];
        if(x == 1) x = n; else x --;
        int la = pos[p[x]];
        pos[a[i]] = i; f[0][i] = la;
        for(int k = 1; (1 << k) <= n - 1; ++ k) f[k][i] = f[k - 1][f[k - 1][i]];
        st[0][i] = cal(n, i);
        //printf("! %d %d %d\n", i, la, cal(n, i));
    }
    for(int k = 1; (1 << k) <= m; ++ k)
        for(int i = 1; i + (1 << k) - 1 <= m; ++ i)
            st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    lo[1] = 0; for(int i = 2; i <= m; ++ i) lo[i] = lo[i >> 1] + 1;
    while(q --)
    {
        int x, y; scanf("%d%d", &x, &y);
        //printf("%d %d %d\n", x, y, find(x, y));
        if(find(x, y) >= x) putchar('1'); else putchar('0');
    }
    puts("");
    return 0;
}