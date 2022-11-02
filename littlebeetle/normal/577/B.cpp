#include<cstdio>
const int N=1002;
int n,m,i,j,k,a,s[N],f[N],g[N];
int main(){
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d",&a);
		s[a%m]++;
	}
	for(i=0;i<m;i++){
		for(j=1;j<=s[i];s[i]-=j,j*=2){
			for(k=0;k<m;k++)
				g[(k+j*i)%m]|=f[k];
			g[j*i%m]=1;
			for(k=0;k<m;k++)
				f[k]|=g[k];	
		}
		if(s[i]){
			j=s[i];
			for(k=0;k<m;k++)
				g[(k+j*i)%m]|=f[k];
			g[j*i%m]=1;
			for(k=0;k<m;k++)
				f[k]|=g[k];	
		}
	}
	printf("%s",f[0]?"YES":"NO");
}