#include<cstdio>
const int N=1002;
int n,m,x,y,i,j,s[N],f[N],g[N];
char c[N][N];
int min(int x,int y){
	return x<y?x:y;
}
void init(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(i=1;i<=n;i++){
		scanf("%s",c[i]+1);
		for(j=1;j<=m;j++)
			s[j]+=c[i][j]=='#';
	}
	for(i=1;i<=m;i++){
		s[i]+=s[i-1];
		f[i]=g[i]=1<<30;
		for(j=i-y;j<=i-x;j++)
			if(j>=0){
			f[i]=min(f[i],g[j]+s[i]-s[j]);
			g[i]=min(g[i],f[j]+(i-j)*n-s[i]+s[j]);
		}
	}
	printf("%d",min(g[m],f[m]));
	//while(1);
}
int main(){
	init();
	//work();
	return 0;
}