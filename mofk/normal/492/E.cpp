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
typedef pair<ll,ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;

ll n,m,dx,dy;
viii a;

void init(void)
{
    scanf("%I64d%I64d%I64d%I64d",&n,&m,&dx,&dy);
    f(i,m)
    {
        ii t;
        scanf("%I64d%I64d",&t.fi,&t.se);
        ll x=((dy*t.fi-dx*t.se)%n+n)%n;
        a.pb(iii(x,t));
    }
    sort(a.begin(),a.end());
}

void process(void)
{
    ll cnt=1,res=1;
    ii ans=a[0].se;
    f(i,m-1)
    {
        if(a[i].fi==a[i-1].fi)
        {
            cnt++;
            if(cnt>res)
            {
                res=cnt;
                ans=a[i].se;
            }
        }
        else cnt=1;
    }
    printf("%I64d %I64d",ans.fi,ans.se);
}

int main(void)
{
    init();
    process();
    return 0;
}