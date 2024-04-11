#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define lb long double
#define N 300005
using namespace std;

int n,a[N];

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	sort(a+1,a+1+n);
	ll ans=0;
	dep(i,n,1) ans+=(ll)a[i]*(i+1);
	printf("%I64d\n",ans-a[n]);
}