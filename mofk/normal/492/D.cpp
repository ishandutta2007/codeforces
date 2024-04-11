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

int n,x,y;
vii a;

void init(void)
{
    scanf("%d%d%d",&n,&x,&y);
    f(i,x) a.pb(ii(1LL*i*y,1));
    f(i,y) a.pb(ii(1LL*i*x,2));
    sort(a.begin(),a.end());
}

void process(void)
{
    f(i,n)
    {
        int t;
        scanf("%d",&t);
        t%=(x+y);
        if(t==0) printf("Both\n");
        else if(a[t-1].se==1&&a[t-1].fi!=a[t].fi) printf("Vanya\n");
        else if(a[t-1].se==2&&(t==1||a[t-1].fi!=a[t-2].fi)) printf("Vova\n");
        else printf("Both\n");
    }
}

int main(void)
{
    init();
    process();
    return 0;
}