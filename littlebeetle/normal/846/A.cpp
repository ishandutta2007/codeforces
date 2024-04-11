#include<cstdio>
const int N=100002;
int n,i,a[N],s1[N],s2[N],ans=1<<30;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		s1[i]=s1[i-1]+(a[i]==1);
	for(i=n;i;i--)
		s2[i]=s2[i+1]+(a[i]==0);
	for(i=1;i<=n+1;i++){
		//printf("%d %d\n",s1[i],s2[i+1]);
		ans=min(ans,s1[i-1]+s2[i]);
	}
	printf("%d",n-ans);
}