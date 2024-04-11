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

int n,x;
vi a;

void init(void)
{
    scanf("%d",&n);
    f(i,n) {scanf("%d",&x);a.pb(x);}
    sort(a.begin(),a.end());
}

void process(void)
{
    if(n==0)
    {
        printf("YES\n1\n1\n3\n3");return;
    }
    if(n==1)
    {
        int i=a[0];
        printf("YES\n%d\n%d\n%d",i,3*i,3*i);
        return;
    }
    if(n==2)
    {
        if(a[0]*3<a[1])
        {
            printf("NO");return;
        }
        if(a[0]*3==a[1])
        {
            printf("YES\n%d\n%d",a[0],a[1]);return;
        }
        printf("YES\n%d\n%d",4*a[0]-a[1],3*a[0]);return;
    }
    if(n==3)
    {
        if(a[0]*3<a[2])
        {
            printf("NO");return;
        }
        if(a[0]*3==a[2])
        {
            printf("YES\n%d",4*a[0]-a[1]);return;
        }
        if(a[1]+a[2]==4*a[0])
        {
            printf("YES\n%d",3*a[0]);return;
        }
        if((a[1]+a[0])*3==4*a[2])
        {
            printf("YES\n%d",a[2]/3);return;
        }
        printf("NO");return;
    }
    if(n==4)
    {
        if((a[1]+a[2]==a[0]+a[3])&&(a[3]=3*a[0]))
        {
            printf("YES");return;
        }
        printf("NO");return;
    }
}

int main(void)
{
    init();
    process();
    return 0;
}