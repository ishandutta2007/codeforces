/*****************************
Author : lizi
Email  : zyli@smail.nju.edu.cn
*****************************/

#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;
const double pi=3.1415926535897932384626;
const double eln=2.718284590452353602874;
#define IN freopen("tmp.in", "r", stdin);
#define OU freopen("tmp.ou", "w", stdout);
#define mp make_pair
#define pb push_back
#define pr1(x) printf("Case %d: ", x);
#define pn1(x) printf("Case %d:\n",x);
#define pr2(x) printf("Case #%d: ", x);
#define pn2(x) printf("Case #%d:\n",x);
#define sqr(x) (x)*(x)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

LL t,n,a,b,k;

bool fuck(LL x, LL aa, LL bb)
{
    if(x <= 0) return true;
    LL s1_d = 0, s1_r = 0, s1_m = 0, s1_g = 0;
    LL s2_d = 0, s2_r = 0, s2_m = 0, s2_g = 0;
    if(a >= x)
    {
        s1_d = aa;
        s1_r = x;
    }else
    {
        s1_m = aa * a / x;
        s1_r = aa * a - x * s1_m;
        s1_d = s1_m + 1;
        s1_g = x - s1_r;
    }
    if(b >= x)
    {
        s2_d = bb;
        s2_r = x;
    }else
    {
        s2_m = bb * b / x;
        s2_r = bb * b - x * s2_m;
        s2_d = s2_m + 1;
        s2_g = x - s2_r;
    }
    if(s1_d + s2_d == k) return min(s1_r, s2_r) >= x;
    if(s1_m + s2_m >= k) return true;
    return ((s1_d + s2_m >= k) || (s2_d + s1_m >= k)) && (s1_g + s2_g <= x);
}

LL judge(LL x, LL aa, LL bb)
{
    if(x <= b) return (aa + bb) >= k;
    if(x > a) return (a * aa + b * bb) / x >= k;
    return (b * bb / x) + aa >= k;
}

LL check()
{
    if(n < k) return 0ll;
    LL aa = (n + 1) >> 1;
    LL bb = n - aa;
    if(a < b){ swap(a,b); swap(aa,bb); }
    LL l=0,r=t;
    while(r-l>1)
    {
        LL mid=(l+r)>>1;
        if(judge(mid,aa,bb))l=mid;else r=mid;
    }
    while(!judge(r,aa,bb))r--;
    return r;
}

int main()
{
    scanf("%lld%lld%lld%lld%lld",&t,&n,&a,&b,&k);
    printf("%lld\n",check());
    return 0;
}