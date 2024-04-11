#include<cstdio>

using namespace std;

int n;
int vis[601],co[601],fa[601],d[601];
int zb(int o,int l,int r){
	int ans1=0,ans2=0;
	int sz=0;
	for(int i=l;i<=r;i++)
		if(!vis[i])sz++;
	if(sz>0){
		printf("? %d\n",sz+1);
		for(int i=l;i<=r;i++)
			if(!vis[i])printf("%d ",i);
		printf("%d\n",o);
		fflush(stdout);
		scanf("%d",&ans1);
	}
	if(sz>1){
		printf("? %d\n",sz);
		for(int i=l,ok=0;i<=r;i++)
			if(!vis[i])printf(!ok?ok=1,"%d":" %d",i);
		printf("\n");
		fflush(stdout);
		scanf("%d",&ans2);
	}
	return ans1-ans2;
}
int nx(int o){
	if(!zb(o,1,n))return 0;
	int l=1,r=n;
	while(l!=r){
		int mid=l+r>>1;
		if(zb(o,l,mid))r=mid;
		else l=mid+1;
	}
	return l;
}
void dfs(int u){
//	printf("?%d\n",u);
	for(;;){
		int v=nx(u);
		if(!v)break;
		vis[v]=1;
		co[v]=co[u]^1;
		fa[v]=u;
		d[v]=d[u]+1;
		dfs(v);
	}
}
int zb2(int o,int l,int r,int*wd){
	int ans1=0,ans2=0;
	int sz=0;
	for(int i=l;i<=r;i++)
		if(wd[i]!=o)sz++;
	if(sz>0){
		printf("? %d\n",sz+1);
		for(int i=l;i<=r;i++)
			if(wd[i]!=o)printf("%d ",wd[i]);
		printf("%d\n",o);
		fflush(stdout);
		scanf("%d",&ans1);
	}
	if(sz>1){
		printf("? %d\n",sz);
		for(int i=l,ok=0;i<=r;i++)
			if(wd[i]!=o)printf(!ok?ok=1,"%d":" %d",wd[i]);
		printf("\n");
		fflush(stdout);
		scanf("%d",&ans2);
	}
	return ans1-ans2;
}
int nx2(int o,int*wd){
	if(!zb2(o,1,wd[0],wd))return 0;
	int l=1,r=wd[0];
	while(l!=r){
		int mid=l+r>>1;
		if(zb2(o,l,mid,wd))r=mid;
		else l=mid+1;
	}
	return wd[l];
}
int ld[601],rd[601];
int dd[601];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(!vis[i])vis[i]=1,co[i]=0,dfs(i);
	for(int i=1;i<=n;i++)
		if(co[i])rd[++rd[0]]=i;
		else ld[++ld[0]]=i;
	for(int i=1;i<=ld[0];i++){
		int u=ld[i],v;
		if(v=nx2(u,ld)){
			for(;u!=v;){
				if(d[u]>d[v])dd[++dd[0]]=u,u=fa[u];
				else dd[++dd[0]]=v,v=fa[v];
			}
			dd[++dd[0]]=u;
			printf("N %d\n",dd[0]);
			for(int i=1;i<=dd[0];i++)
				printf("%d%c",dd[i],i==dd[0]?'\n':' ');
			return 0;
		}
	}
	for(int i=1;i<=rd[0];i++){
		int u=rd[i],v;
		if(v=nx2(u,rd)){
			for(;u!=v;){
				if(d[u]>d[v])dd[++dd[0]]=u,u=fa[u];
				else dd[++dd[0]]=v,v=fa[v];
			}
			dd[++dd[0]]=u;
			printf("N %d\n",dd[0]);
			for(int i=1;i<=dd[0];i++)
				printf("%d%c",dd[i],i==dd[0]?'\n':' ');
			return 0;
		}
	}
	printf("Y %d\n",ld[0]);
	for(int i=1;i<=ld[0];i++)
		printf("%d%c",ld[i],i==ld[0]?'\n':' ');
}