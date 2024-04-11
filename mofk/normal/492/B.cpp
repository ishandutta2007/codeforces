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

int n,l;
vi a;

void init(void)
{
    scanf("%d%d",&n,&l);
    f(i,n) {int x;scanf("%d",&x);a.pb(x);}
    sort(a.begin(),a.end());
}

void process(void)
{
    double res=max(a[0],l-a[n-1]);
    f(i,n-1) res=max(res,(double)(a[i]-a[i-1])/2);
    printf("%.11lf",res);
}

int main(void)
{
    init();
    process();
    return 0;
}