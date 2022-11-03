#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=505;

int n,k,a[N];//,b[N];

void solve(){
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",a+i);
	a[0]=a[n+1]=k;
	int ans=0;
	rep(i,1,n){
		int tmp=max(a[i],k-a[i-1])-a[i];
		a[i]+=tmp;
		ans+=tmp;
	}
	printf("%d\n",ans);
	rep(i,1,n) printf("%d ",a[i]);
	puts("");
}

int main(){
	//	freopen("1.in","r",stdin);
	//	Freopen("1.out","w",stdout);

	int ca=1;
	//scanf("%d",&ca);
	while(ca--){
		solve();
	}
}