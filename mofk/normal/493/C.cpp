#include<bits/stdc++.h>
#define f(i,n) for(int i=1;i<=n;i++)
#define F(i,n) for(int i=n;i>=1;i--)
#define FF(i,a,b) for(int i=a;i>=b;i--)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
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

ll n,m;
ll res=0,pa=0,pb=0,diff=0;
vii a;
ii ans;

void init(void)
{
    scanf("%I64d",&n);
    f(i,n)
    {
        ll x;
        scanf("%I64d",&x);
        a.pb(ii(x,1));
    }
    scanf("%I64d",&m);
    f(i,m)
    {
        ll x;
        scanf("%I64d",&x);
        a.pb(ii(x,2));
    }
    sort(a.begin(),a.end());
}

void process(void)
{
    diff=res=3*(n-m);
    pa=3*n;
    pb=3*m;
    ans=mp(pa,pb);
    ff(i,0,a.size()-1)
    {
        if(a[i].se==1)
        {
            diff--;
            pa--;
        }
        else
        {
            diff++;
            pb--;
        }
        if(i==a.size()-1||a[i].fi!=a[i+1].fi)
        {
            if(diff>res)
            {
                res=diff;
                ans=mp(pa,pb);
            }
        }
    }
    printf("%I64d:%I64d",ans.fi,ans.se);
}

int main(void)
{
    init();
    process();
    return 0;
}