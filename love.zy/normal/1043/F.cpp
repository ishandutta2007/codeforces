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

const int mod=1e9+7;
const int maxn=300005;
int jc[maxn],ny[maxn],mu[maxn];
vi ys[maxn];

int mi(int x,int y)
{
    int ret=1;
    while(y>0)
    {
        if(y&1)ret=1ll*ret*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ret;
}

void precal()
{
	mu[1]=1;
    for(int i=1;i<=maxn-5;i++)
    {
        if(!mu[i])continue;
        for(int j=i;j<=maxn-5;j+=i)ys[j].pb(i);
        for(int j=i<<1;j<=maxn-5;j+=i)mu[j]-=mu[i];
    }
    jc[0]=1;for(int i=1;i<=maxn-5;i++)jc[i]=1ll*i*jc[i-1]%mod;
    ny[maxn-5]=mi(jc[maxn-5],mod-2);
    for(int i=maxn-5-1;i>=0;i--)ny[i]=1ll*(i+1)*ny[i+1]%mod;
}

int C(int x,int y){if(x<y)return 0;else return 1ll*jc[x]*(1ll*ny[y]*ny[x-y]%mod)%mod;}

int cnt[maxn],n;

bool check(int k)
{
    int sum=0;
    for(int i=maxn-5;i>=1;i--)sum=(sum+(mod+1ll*mu[i]*C(cnt[i],k)%mod))%mod;
    return sum>0;
}

int main()
{
    precal();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        for(int p : ys[x])cnt[p]++;
    }
    int l=1,r=min(10,n);
    if(!check(r)){puts("-1");return 0;}
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;else l=mid;
    }
    while(!check(l))l++;
    printf("%d\n",l);
    return 0;
}