#include<bits/stdc++.h>
#define f(i,n) for(int i=1;i<=n;i++)
#define F(i,n) for(int i=n;i>=1;i--)
#define FF(i,a,b) for(int i=a;i>=b;i--)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define B 1
#define W -1
typedef long long ll;
using namespace std;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5;
const ll mod=1e9+7,INF=1<<30;

ll n,r,avg,tl=0,res=0;
vii a;

void init(void)
{
    scanf("%I64d%I64d%I64d",&n,&r,&avg);
    f(i,n)
    {
        ii x;
        scanf("%I64d%I64d",&x.se,&x.fi);
        tl+=x.se;
        a.pb(x);
    }
    sort(a.begin(),a.end());
}

void process(void)
{
    ll it=0,tar=avg*n;
    while(tl<tar)
    {
        if(a[it].se<r)
        {
            ll b=min(tar-tl,r-a[it].se);
            tl+=b;
            a[it].se+=b;
            res+=a[it].fi*b;
        }
        it++;
    }
    printf("%I64d",res);
}

int main(void)
{
    init();
    process();
    return 0;
}