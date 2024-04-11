#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5002;
struct q{
	int l,r,id;
	bool operator<(const q &x)const{
		if(x.l!=l)
			return x.l>l;
		return x.id>id;
	}
}a[N];
int t,n,i,k,ans[N];
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
		sort(a+1,a+n+1);
		for(k=0,i=1;i<=n;i++)
			if(k+1>a[i].r)
				ans[a[i].id]=0;
			else
				ans[a[i].id]=k=max(k+1,a[i].l);
		for(i=1;i<=n;i++)
			printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}