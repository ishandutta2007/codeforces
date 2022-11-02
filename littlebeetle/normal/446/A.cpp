#include<cstdio>
const int N=1000003;
int n,a[N],i,L[N],R[N],ans=1;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	L[1]=1;
	for(i=2;i<=n;i++)
		if(a[i]>a[i-1])
			L[i]=L[i-1]+1;
		else
			L[i]=1;
	R[n]=1;
	for(i=n-1;i;i--)
		if(a[i]<a[i+1])
			R[i]=R[i+1]+1;
		else
			R[i]=1;
	for(i=1;i<n;i++)
		ans=max(L[i]+1,ans);
	for(i=2;i<=n;i++)
		ans=max(R[i]+1,ans);
	for(i=2;i<n;i++)
		if(a[i-1]+1<a[i+1])
			ans=max(L[i-1]+1+R[i+1],ans);
	printf("%d",ans);
	//while(1);
}