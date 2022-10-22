#include<cstdio>
const int MAXN=5005;
int n;
int cnte,h[MAXN],nx[MAXN<<1],to[MAXN<<1];
int ind[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
	ind[v]++;
}
int ans;
int a[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	while(1){
		*a=0;
		for(int i=1; i<=n; i++)
			if(ind[i]==1) a[++*a]=i;
		if(*a==0){
			for(int i=1; i<=n; i++)
				if(ind[i]==0) ans=i;
			break;
		}
		int u=a[1],v=a[2];
		printf("? %d %d\n",u,v);
		fflush(stdout);
		int w;
		scanf("%d",&w);
		if(w==u||w==v){
			ans=w;
			break;
		}
		for(int i=h[u]; i; i=nx[i])
			ind[to[i]]--;
		ind[u]=-1;
		for(int i=h[v]; i; i=nx[i])
			ind[to[i]]--;
		ind[v]=-1;
	}
	printf("! %d\n",ans);
	return 0;
}