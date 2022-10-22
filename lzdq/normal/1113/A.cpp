#include<cstdio>
#include<cstring>
inline int minn(int a,int b){
	if(a<b) return a;
	return b;
}
const int MAXN=205,MAXW=105;
int n,w;
int f[MAXN][MAXW];
int main(){
	scanf("%d%d",&n,&w);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(i==1&&j==0){
				f[i][j]=0;
				continue;
			}
			f[i][j]=f[i-1][j+1];
			if(j) f[i][j]=minn(f[i][j],f[i][j-1]+i);
		}
	}
	printf("%d\n",f[n][0]);
	return 0;
}