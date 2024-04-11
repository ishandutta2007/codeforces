#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
const int N=200002,K=19;
int n,m,i,j,k,a,b,cnt,c[N],h[N],t[N],v[N],sz[N],d[N],dfn[N],bfn[N],dsa[N],bsa[N],w[N],q[N],s,e,pc[N];
int rt[N],T[N*K],L[N*K],R[N*K],l,r,Lb[N],Rb[N],mid;
map<string,int>P;
string S;
void dfs(int i){
	sz[i]=1;
	dfn[i]=++cnt;
	dsa[cnt]=i;
	for(int j=h[i];j;j=t[j]){
		d[v[j]]=d[i]+1;
		dfs(v[j]);
		sz[i]+=sz[v[j]];
	}
}
void bfs(){
	s=0;e=-1;
	for(i=1;i<=n;i++)
		if(d[i]==0)
			q[++e]=i;
	while(s<=e){
		i=q[s++];
		bfn[i]=++cnt;
		if(!Lb[d[i]])Lb[d[i]]=bfn[i];
		Rb[d[i]]=bfn[i];
		bsa[cnt]=i;
		for(int j=h[i];j;j=t[j])
				q[++e]=v[j];
	}
}
void Update(int pre,int &rt,int l,int r,int x){
	if(!rt)rt=++cnt;
	T[rt]=T[pre]+1;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)
		R[rt]=R[pre],Update(L[pre],L[rt],l,mid,x);
	else
		L[rt]=L[pre],Update(R[pre],R[rt],mid+1,r,x);
}
int Get1(int l,int r){
	while(l<r){
		mid=l+r>>1;
		if(dfn[bsa[mid]]>=dfn[i])
			r=mid;
		else
			l=mid+1;
	}
	return r;
}
int Get2(int l,int r){
	while(l<r){
		mid=l+r+1>>1;
		if(dfn[bsa[mid]]<dfn[i]+sz[i])
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
int Query(int pre,int nxt,int l,int r,int x){
	if(x==0)return 0;
	if(r<=x)return T[nxt]-T[pre];
	int mid=l+r>>1,s=0;
	s=Query(L[pre],L[nxt],l,mid,x);
	if(x>mid)
		s+=Query(R[pre],R[nxt],mid+1,r,x);
	return s;
}
int main(){
	scanf("%d",&n);
	for(b=1;b<=n;b++){
		cin>>S>>a;
		if(!P[S])P[S]=++cnt;
		c[b]=P[S];
		t[++k]=h[a];h[a]=k;v[k]=b;
	}
	k=cnt;
	cnt=0;
	for(i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	cnt=0;
	bfs();
	cnt=0;
	for(i=1;i<=n;i++){
		k=bsa[i];
		Update(rt[i-1],rt[i],0,n,pc[c[k]]);
		pc[c[k]]=i;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&i,&k);
		l=Get1(Lb[d[i]+k],Rb[d[i]+k]);
		r=Get2(Lb[d[i]+k],Rb[d[i]+k]);
		if(dfn[bsa[r]]>=dfn[i]+sz[i]||dfn[bsa[l]]<dfn[i])
			printf("0\n");
		else{
			//printf("%d %d    ",l,r);
			printf("%d\n",Query(rt[l-1],rt[r],0,n,l-1));
		}
	}
	//while(1);
}