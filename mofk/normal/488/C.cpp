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

int b[3][4],h,a,d;

void init(void)
{
    f(i,2) f(j,3) scanf("%d",&b[i][j]);
    scanf("%d%d%d",&h,&a,&d);
}

void process(void)
{
    int def=max(0,b[2][2]-b[1][3]),off=max(0,b[1][2]-b[2][3]);
    if(!def)
    {
        if(!off) {printf("%d",(b[2][3]-b[1][2]+1)*a);return;}printf("0");return;
    }
    int tmp=0,hp=b[1][1]-1,hpm=b[2][1]-1;
    if(!off) {tmp=(b[2][3]-b[1][2]+1)*a;off=1;}
    int res=def*d+tmp;
    ff(n,0,def-1)
    {
        int ans=1e9,ndef=def-n,noff=off;
        ff(p,0,100)
        {
            int tar=hpm/noff;
            int m=max(0,(tar+1)*ndef-hp);
            ans=min(ans,m*h+n*d+p*a+tmp);
            noff++;
        }
        res=min(res,ans);
    }
    printf("%d",res);
}

int main(void)
{
    init();
    process();
    return 0;
}