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

int n;
bool pr[MAX];

int modInv(int a,int m)
{
    int xa=1,xm=0,tmp=m;
    while(m)
    {
        int q=a/m;
        int xr=xa-q*xm;
        xa=xm;xm=xr;
        int r=a%m;
        a=m;m=r;
    }
    while(xa<0) xa+=tmp;
    return xa;
}

void init(void)
{
    scanf("%d",&n);
}

void process(void)
{
    if(n==1) {printf("YES\n1");return;}
    if(n==4)
    {
        printf("YES\n1\n3\n2\n4");return;
    }
    for(int i=2;i*i<=n;i++) if(n%i==0)
    {
        printf("NO");return;
    }
    printf("YES\n1\n");
    f(i,n-2) printf("%d\n",modInv(i,n)+1);
    printf("%d",n);
}

int main(void)
{
    init();
    process();
    return 0;
}