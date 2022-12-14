#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define mo 1000000007
#define N 1005
int n,m,k,x,y,c[N],fa[N],sz[N],vis[N],spe[N];
int largest,rest,ans;
int father(int x){
	return fa[x]==x?x:fa[x]=father(fa[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rpt(i,1,k) scanf("%d",&c[i]);
	rpt(i,1,n) fa[i]=i,sz[i]=1,vis[i]=spe[i]=0;
	rpt(i,1,m){
		scanf("%d%d",&x,&y);
		if(father(x)==father(y)) continue;
		sz[father(y)]+=sz[father(x)];fa[father(x)]=father(y);
	}
	rpt(i,1,k) spe[father(c[i])]=1;
	largest=0;rest=n;ans=0;
	rpt(i,1,n){
		x=father(i);
		if(vis[x]) continue;
		vis[x]=1;
		if(spe[x]){
			if(sz[x]>largest) ans+=largest*(largest-1)/2,largest=sz[x];
			else ans+=sz[x]*(sz[x]-1)/2;
			rest-=sz[x];
		}
	}
	ans+=(rest+largest)*(rest+largest-1)/2;
	printf("%d",ans-m);
}