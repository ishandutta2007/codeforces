#include<cstdio>
const int N=3002;
int n,k,i,j,p[N],g[N],f[N],s[N],ans,t;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",p+i);
	for(i=n;i;i--){
		s[i]=s[i+1]+p[i];
		f[i]=f[i+1]|(p[i]==100);
		g[i]=1<<30;
	}
	for(i=1;i<=n;i++){
		if(s[i+1]&&p[i]!=100)g[i]=min(g[i],g[i-1]+1);
		if(s[i]&&p[i-1])g[i]=min(g[i],g[i-2]+1);
		if(g[i]<=k)
			ans++;
		if(p[i]&&!f[i+1])
			for(j=i+1;j<=n&&j-i+g[i-1]<=k;j++){
				ans++;
				if(s[j])
					g[j]=min(g[j],g[i-1]+j-i);
			}
	}
	printf("%d",ans+1);
	return 0;
}