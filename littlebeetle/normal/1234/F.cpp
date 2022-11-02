#include<cstdio>
const int N=1000002,M=20;
char s[N];
int n,i,j,p,f[1<<M],g[1<<M],ans;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%s",s+1);
	while(s[n+1])
		n++;
	for(i=1;i<=n;i++){
		j=i;
		p=0;
		while(j<=n&&!(p>>(s[j]-97)&1)){
			p|=1<<(s[j]-97);
			f[p]=j-i+1;
			g[p]=j-i+1;
			j++;
		}
	}
	for(j=0;j<20;j++)
		for(i=1;i<(1<<M);i++)
			if(i>>j&1)
			g[i]=max(g[i],g[i^1<<j]);
	for(i=0;i<(1<<M);i++)
		ans=max(ans,f[i]+g[i^((1<<M)-1)]);
	printf("%d",ans);
	//while(1);
}