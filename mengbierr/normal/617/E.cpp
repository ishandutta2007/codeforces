#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#define ll long long  
using namespace std;  
int const MAXN = 100005;  
int const MAXM = 10000005;  
int const CON = sqrt(MAXN);  
ll sum[MAXN], a[MAXN], ans[MAXN], num;  
ll cnt[MAXM];  
int n, m, k;  
  
struct DATA  
{  
    int l, r, id;  
}d[MAXN];  
  
bool cmp(DATA a, DATA b)  
{  
    if(a.l / CON == b.l / CON)  
        return a.r / CON < b.r / CON;  
    return a.l / CON < b.l / CON;  
}  
  
void Add(int x) //sum[l - 1]  
{  
    num += cnt[x ^ k];   
    cnt[x] ++;  
}  
  
void Sub(int x) //sum[l - 1]  
{  
    cnt[x] --;  
    num -= cnt[x ^ k];  
}  
  
int main()  
{  
    scanf("%d %d %d", &n, &m, &k);  
    for(int i = 1; i <= n; i++)  
    {  
        scanf("%I64d", &a[i]);  
        sum[i] = sum[i - 1] ^ a[i];  
    }  
    for(int i = 0; i < m; i++)  
    {  
        scanf("%d %d", &d[i].l, &d[i].r);  
        d[i].id = i;  
        d[i].l -= 1;  
    }  
    sort(d, d + m, cmp);  
    int l = 0, r = 0;  
    num = 0;  
    cnt[0] = 1;  
    for(int i = 0; i < m; i++)  
    {  
        while(l < d[i].l)  
            Sub(sum[l ++]);   
        while(l > d[i].l)  
            Add(sum[-- l]); //  
        while(r < d[i].r)  
            Add(sum[++ r]); //  
        while(r > d[i].r)  
            Sub(sum[r --]);  
        ans[d[i].id] = num;  
    }  
    for(int i = 0; i < m; i++)  
        printf("%I64d\n", ans[i]);  
}