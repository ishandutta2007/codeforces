#include<cstdio>
const int N=1000002;
int n,a[N],x,y,i,ans;
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(i=n-1;i>=0;i--)
		scanf("%1d",a+i);
	for(i=0;i<x;i++)
		if(i!=y)
			ans+=a[i];
	ans+=a[y]^1;
	printf("%d",ans);
}