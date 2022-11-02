#include<cstdio>
const int N=1000002;
int n,t,c,i,a[N],s[N],ans;
int main(){
	scanf("%d%d%d",&n,&t,&c);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	a[++n]=t+1;
	for(i=1;i<=n;i++)
		if(a[i]<=t)
			s[i]=s[i-1]+1;
	for(i=1;i<=n;i++)
		if(!s[i+1]&&s[i]>=c)
			ans+=s[i]-c+1;
	printf("%d",ans);
}