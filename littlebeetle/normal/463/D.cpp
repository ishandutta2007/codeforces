#include<cstdio>
const int N=1002,K=5;
int n,k,i,j,p,a,f[N][K],g[N],t,s,b[N];
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d",&n,&k);
	for(j=0;j<k;j++)
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			f[a][j]=i;
			b[i]=a;
		}
	for(a=1;a<=n;a++){
		i=b[a];
		//printf("%d\n",i);
		for(j=1;j<=n;j++){
			t=1;
			for(p=0;p<k;p++)
				if(f[i][p]<=f[j][p])
					t=0;
			if(t)
				g[i]=max(g[i],g[j]);
		}
		g[i]++;
		if(g[i]>s)
			s=g[i];
	}
	printf("%d",s);
	//while(1);
}