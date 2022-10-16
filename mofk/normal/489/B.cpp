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

int n,m,x;
vi a,b;

void init(void)
{
    scanf("%d",&n);
    f(i,n) {scanf("%d",&x);a.pb(x);}
    scanf("%d",&m);
    f(i,m) {scanf("%d",&x);b.pb(x);}
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
}

void process(void)
{
    int p1=0,p2=0,cnt=0;
    while((p1<n)&&(p2<m))
    {
        if(a[p1]-b[p2]<=1&&b[p2]-a[p1]<=1)
        {
            cnt++;
            p1++;
            p2++;
        }
        else if(a[p1]>b[p2]) p2++;
        else p1++;
    }
    printf("%d",cnt);
}

int main(void)
{
    init();
    process();
    return 0;
}