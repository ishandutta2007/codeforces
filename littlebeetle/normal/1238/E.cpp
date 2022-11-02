#include<cstdio>
#include<cstring>
const int M=1<<20,L=100020;
char s[L];
int n,m,g[M],f[M],i,j,k,x,y,D;
void init(){
	scanf("%d%d%s",&n,&m,s+1);
	D=(1<<m)-1;
	for(i=1;i<n;i++){
		x=s[i]-97;
		y=s[i+1]-97;
		if(x!=y)
		g[1<<x|1<<y]++;
	}
	for(j=0;j<m;j++)
		for(i=0;i<=D;i++)
			if(i>>j&1)
				g[i]+=g[i^1<<j];
}
int min(int x,int y){
	return x<y?x:y;
}
void work(){
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(i=0;i<=D;i++)
		for(j=0;j<m;j++)
			if((i>>j&1)==0)
				f[i|1<<j]=min(f[i|1<<j],f[i]+g[D]-g[i]-g[D^i]);
	printf("%d",f[D]);
}
int main(){
	init();
	work();
	return 0;
}