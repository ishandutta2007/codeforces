#include<cstdio>
const int N=10002;
int n,i,a[N],ans;
void dfs(int l,int r){
	int i,f=1;
	for(i=l;i<r;i++)
		if(a[i]>a[i+1])
			f=0;
	if(f&&r-l+1>ans)
		ans=r-l+1;
	if(l!=r){
		int mid=l+r>>1;
		dfs(l,mid);
		dfs(mid+1,r);
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	dfs(1,n);
	printf("%d",ans);
}