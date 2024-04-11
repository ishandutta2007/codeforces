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

int n,a[3005];
vii ans;

void init(void)
{
    scanf("%d",&n);
    ff(i,0,n-1) scanf("%d",&a[i]);
}

void process(void)
{
    ff(i,0,n-2) {
        int tmp=i;
        FF(j,n-1,i+1) if(a[j]<a[tmp]) tmp=j;
        ans.pb(ii(i,tmp));
        swap(a[i],a[tmp]);
    }
    printf("%d\n",ans.size());
    if(!ans.empty()) ff(i,0,ans.size()-1) printf("%d %d\n",ans[i].fi,ans[i].se);
}

int main(void)
{
    init();
    process();
    return 0;
}