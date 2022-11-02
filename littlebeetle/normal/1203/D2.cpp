#include<cstdio>
const int N=200002;
char s[N],t[N];
int n,m,i,j,f[N],g[N],ans;
int max(int x,int y){
	return x>y?x:y; 
}
int main(){
	scanf("%s%s",s+1,t+1);
	for(n=0;s[n+1];n++);
	for(m=0;t[m+1];m++);
	for(i=1;i<=n;i++){
		f[i]=f[i-1];
		if(s[i]==t[f[i]+1])
			f[i]++;
	}
	g[n+2]=1<<30;
	g[n+1]=m+1;
	for(i=n;i;i--){
		g[i]=g[i+1];
		if(s[i]==t[g[i]-1])
			g[i]--;
	}
	for(i=0,j=0;i<=n;i++){
		while(g[j+1]-f[i]<=1)
			j++;
		ans=max(ans,j-i-1);
	}
	printf("%d",ans);
}