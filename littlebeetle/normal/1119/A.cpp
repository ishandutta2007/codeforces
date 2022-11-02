#include<cstdio>
const int N=300002;
int n,i,ans,s[N];
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",s+i);
	for(i=2;i<=n;i++)
		if(s[i]!=s[1])
			ans=max(ans,i-1);
	for(i=1;i<n;i++)
		if(s[i]!=s[n])
			ans=max(ans,n-i);		
	printf("%d",ans);
}