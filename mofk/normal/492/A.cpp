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



void init(void)
{
    int n,res=0,s=0;
    scanf("%d",&n);
    while(s<=n)
    {
        res++;
        s+=res*(res+1)/2;
    }
    printf("%d",res-1);
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