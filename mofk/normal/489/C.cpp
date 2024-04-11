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

int m,s;
char ans[105];

void init(void)
{
    scanf("%d%d",&m,&s);
}

void process(void)
{
    if(m!=1&&s==0)
    {
        printf("-1 -1");return;
    }
    if(s>9*m)
    {
        printf("-1 -1");return;
    }
    if(m==1&&s==0)
    {
        printf("0 0");return;
    }
    int a=m,b=s;int it=0;
    while(b>9)
    {
        ans[it]='9';
        a--;b-=9;it++;
    }
    ans[it]='0'+b;
    ff(i,it+1,m-1) ans[i]='0';
    char ans2[105]="";
    ff(i,0,m-1) ans2[i]=ans[m-1-i];
    if(ans2[0]=='0')
    {
        ans2[0]='1';
        f(i,m-1) if(ans2[i]>'0') {ans2[i]--;break;}
    }
    printf("%s %s",ans2,ans);
}

int main(void)
{
    init();
    process();
    return 0;
}