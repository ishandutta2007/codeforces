#include<cstdio>
const int MAXN=1e5+5;
int n,u[MAXN],v[MAXN],w[MAXN];
int ind[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++)
		scanf("%d%d",u+i,v+i),ind[u[i]]++,ind[v[i]]++,w[i]=-1;
	int m=0;
	for(int i=1; i<=n; i++)
		if(ind[i]>=3){
			for(int j=1; j<n; j++)
				if(u[j]==i||v[j]==i){
					w[j]=m++;
					if(m==3) break;
				}
			break;
		}
	for(int i=1; i<n; i++)
		if(w[i]==-1) w[i]=m++;
	for(int i=1; i<n; i++)
		printf("%d\n",w[i]);
	return 0;
}