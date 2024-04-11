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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5;
const ll mod=1e9+7,INF=1<<30;

int n,ex1[1000005],ex2[1000005];
vii a;
vi res1,res2;

void s(int x)
{
    int i=ex1[x];
    if(i==-1) return;
    if(a[i].se)
    {
        res1.pb(a[i].se);
        s(a[i].se);
    }
}

void s2(int x)
{
    int i=ex2[x];
    if(i==-1) return;
    if(a[i].fi)
    {
        res2.pb(a[i].fi);
        s2(a[i].fi);
    }
}

void init(void)
{
    scanf("%d",&n);
    int x,y;
    ff(i,0,1000000)
    {
        ex1[i]=ex2[i]=-1;
    }
    ff(i,0,n-1)
    {
        scanf("%d%d",&x,&y);
        a.pb(ii(x,y));
        ex1[x]=ex2[y]=i;
    }
}

void process(void)
{
    s(0);
    if(!(n&1))
    {
        s2(0);
        int d=res1.size()-1;
        ff(i,0,d) printf("%d %d ",res2[d-i],res1[i]);
        return;
    }
    ff(i,0,n-1) if(ex1[a[i].se]==-1)
    {
        s2(a[i].se);
        int d=res1.size()-1;
        //ff(j,0,res2.size()-1) printf("%d ",res2[j]);
        ff(j,0,d) printf("%d %d ",res2[d-j],res1[j]);
        printf("%d",a[i].se);
        return;
    }
}

int main(void)
{
    init();
    process();
    return 0;
}