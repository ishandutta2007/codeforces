#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002,K=20;
int n,o,m,i,j,k,x,y,a[N],h[N],t[N],v[N],fa[N],dep[N],sz[N],dfn[N],T,id[N],rt[N],L[N*K],R[N*K],s[N*K],Dep,ans,cnt;
int max(int x,int y){
	return x>y?x:y;
}
void dfs(int i){
	dfn[i]=++T;
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]){
			fa[v[j]]=i;
			dep[v[j]]=dep[i]+1;
			dfs(v[j]);
			sz[i]+=sz[v[j]];
		}
	Dep=max(Dep,dep[i]);
}
bool cmp(int x,int y){
	return dep[x]<dep[y];
}
int min(int x,int y){
	return x<y?x:y;
}
void Update(int pre,int &rt,int l,int r,int a,int x){
	rt=++cnt;
	if(l==r){
		s[rt]=a;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		R[rt]=R[pre],Update(L[pre],L[rt],l,mid,a,x);
	else
		L[rt]=L[pre],Update(R[pre],R[rt],mid+1,r,a,x);
	s[rt]=min(s[L[rt]],s[R[rt]]);
}
int Query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return s[rt];
	int a=1<<30,mid=l+r>>1;
	if(x<=mid)
		a=min(a,Query(L[rt],l,mid,x,y));
	if(y>mid)
		a=min(a,Query(R[rt],mid+1,r,x,y));
	return a;
}
int main(){
	scanf("%d%d",&n,&o);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),id[i]=i;
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		t[++k]=h[x];h[x]=k;v[k]=y;
		t[++k]=h[y];h[y]=k;v[k]=x;
	}
	dfs(o);
	sort(id+1,id+n+1,cmp);
	s[0]=1<<30;
	for(i=1;i<=n;i++)
		Update(rt[dep[id[i-1]]],rt[dep[id[i]]],1,n,a[id[i]],dfn[id[i]]);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&k);
		x=(x+ans)%n+1;
		k=(k+ans)%n;
		printf("%d\n",ans=Query(rt[min(Dep,dep[x]+k)],1,n,dfn[x],dfn[x]+sz[x]-1));
	}
	return 0;
}