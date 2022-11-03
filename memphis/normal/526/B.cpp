#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define N 5005

int n,a[N],m,ans,t[N];

int main(){
	scanf("%d",&n);
	m=(1<<n+1)-1;
	rep(i,2,m) scanf("%d",a+i);
	dep(i,(1<<n)-1,1){
		t[i]=max(t[i<<1]+a[i<<1],t[i<<1|1]+a[i<<1|1]);
		ans+=t[i<<1]+a[i<<1]-t[i]+t[i<<1|1]+a[i<<1|1]-t[i];
	}
	printf("%d\n",ans*-1);
}