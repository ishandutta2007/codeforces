#include<cstdio>
const int N=500002;
int n,c,s[N],f[N],p[N],i,a[N],S[N],ans;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d",&n,&c);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),s[i]=s[i-1]+(a[i]==c);
	for(i=n;i;i--)
		S[i]=S[i+1]+(a[i]==c);
	ans=s[n];
	for(i=1;i<=n;i++)
		if(a[i]!=c){
			f[a[i]]=max(f[a[i]],-p[a[i]]+s[i]);
			p[a[i]]++;
			ans=max(ans,p[a[i]]+f[a[i]]+S[i+1]);
		}
	printf("%d",ans);
	return 0;
}