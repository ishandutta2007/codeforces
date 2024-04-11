#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
//#include<set>
//#include<map>
#include<queue>
//#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define rev(it,v) for(vector<int>::iterator it=v.begin();it!=v.end();it++)
using namespace std;
#define N 200005
#define LL long long

int n,sn[N],nx[N<<1],ed[N<<1],x,y,f[N],sz[N];

void dfs1(int x,int fa,int v){
	sz[x]=0;
	for(int j=sn[x];j;j=nx[j])
		if(ed[j]^fa){
			dfs1(ed[j],x,v^1);
			sz[x]+=sz[ed[j]];
		}
	if(sz[x]==0){
		sz[x]=1;
		f[x]=1;
		return;
	}
	if(v==0){
		
		f[x]=sz[x];
		for(int j=sn[x];j;j=nx[j])
			if(ed[j]^fa){
				f[x]=min(f[x],sz[ed[j]]-f[ed[j]]+1);
			}
	}else{
		int tot=0;
		for(int j=sn[x];j;j=nx[j])
			if(ed[j]^fa)
				tot+=sz[ed[j]]-f[ed[j]];
		f[x]=tot+1;
	}
}

int main(){
	scanf("%d",&n);
	rep(i,2,n){
		scanf("%d%d",&x,&y);
		nx[i]=sn[x],sn[x]=i,ed[i]=y;
		nx[i+n]=sn[y],sn[y]=i+n,ed[i+n]=x;
	}
	if(n==1){
		puts("1 1");
		return 0;
	}
	dfs1(1,0,0);
	printf("%d ",sz[1]-f[1]+1);
	dfs1(1,0,1);
	printf("%d\n",sz[1]-f[1]+1);
}