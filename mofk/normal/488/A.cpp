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

bool c(int n)
{
    if(n<0) return c(-n);
    while(n)
    {
        if(n%10==8) return 1;
        n/=10;
    }
    return 0;
}

void init(void)
{
    int n;
    scanf("%d",&n);
    f(i,100)
    {
        n++;
        if(c(n)) {printf("%d",i);return;}
    }
}

void process(void)
{

}

int main(void)
{
    init();
    process();
    return 0;
}