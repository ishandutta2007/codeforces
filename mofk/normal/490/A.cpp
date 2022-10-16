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

vi a,b,c;
int n,x;

void init(void)
{
    scanf("%d",&n);
    f(i,n)
    {
        scanf("%d",&x);
        if(x==1) a.pb(i);
        if(x==2) b.pb(i);
        if(x==3) c.pb(i);
    }
}

void process(void)
{
    if(a.empty()&&b.empty()&&c.empty())
    {
        printf("0");return;
    }
    int d=min(min(a.size(),b.size()),c.size());
    printf("%d",d);
    ff(i,0,d-1) printf("\n%d %d %d",a[i],b[i],c[i]);
}

int main(void)
{
    init();
    process();
    return 0;
}