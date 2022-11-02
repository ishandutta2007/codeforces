#include<cstdio>
const int N=200002;
int n,q,i,j,a[N],x,f[N],g[N],F[N];
int p(int x){
	return x==F[x]?x:F[x]=p(F[x]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=x;
		if(x>q){
			printf("NO");
			return 0;
		}
		if(!f[x])
			f[x]=i;
		g[x]=i;
		F[i]=i;
	}
	for(i=q;i;i--){
		if(g[i]){
			j=g[i];
			while((j=p(j))>=f[i]){
				if(a[j]&&a[j]<i){
					printf("NO");
					return 0;
				}
				F[j]=j-1;
			}
		}
	}
	a[0]=1;
	if(!g[q]){
		for(j=0,i=1;i<=n;i++)
			if(!a[i]){
				a[i]=q;
				j=1;
				break;
			}
		if(!j){
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++){
		if(!a[i])
			a[i]=a[i-1];
		printf("%d ",a[i]);
	}
}