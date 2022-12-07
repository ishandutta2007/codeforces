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

const LL mod = 1ll<<32;
vector<LL> b;
LL ma,mi,ze,l,r,x,y,z,ans,b1,b2;
int n,T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        mi = 2e9 + 1; ans = (LL)8e18;
        b.clear();
        scanf("%d%lld%lld%lld%lld%lld%lld%lld",&n,&l,&r,&x,&y,&z,&b1,&b2);
        b.pb(b1);b.pb(b2);
        for(int i=2;i<n;i++)b.pb(((b[i-2]*x+b[i-1]*y+z)%mod+mod)%mod);
        for(int i=0;i<n;i++)
        {
            LL a = (b[i]%(r-l+1))+l;
            if(mi < 2e9 + 1 && mi < a) ans = min(ans, a * mi);
            mi = min(mi, a);
        }
        mi = -2e9 - 1;
        for(int i=n-1;i>=0;i--)
        {
            LL a = (b[i]%(r-l+1))+l;
            if(a >= 0) continue;
            if(mi > a) ans = min(ans, mi * a);
            mi = max(mi, a);
        }
        if(ans == (LL)8e18)puts("IMPOSSIBLE");else printf("%lld\n",ans);
    }
    return 0;
}