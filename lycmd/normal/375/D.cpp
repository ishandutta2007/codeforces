#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,b,q,dfn,cur[N],a[N],c[N],cnt[N],ans[N],ldfn[N],rdfn[N];
vector<int>e[N];
struct query{
	int l,r,k,id;
	int operator<(const query&rhs)const{
		return l/b<rhs.l/b||l/b==rhs.l/b&&r<rhs.r;
	}
}p[N];
void add(int x){
	cur[++cnt[c[x]]]++;
}
void del(int x){
	cur[cnt[c[x]]--]--;
}
void dfs(int x,int fa){
	c[ldfn[x]=++dfn]=a[x];
	for(int y:e[x])
		if(y^fa)dfs(y,x);
	rdfn[x]=dfn;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q,b=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=q;i++){
		int a,b;cin>>a>>b;
		p[i]={ldfn[a],rdfn[a],b,i};
	}
	sort(p+1,p+1+q);
	int l=1,r=0;
	for(int i=1;i<=q;i++){
		while(l<p[i].l)del(l++);
		while(l>p[i].l)add(--l);
		while(r<p[i].r)add(++r);
		while(r>p[i].r)del(r--);
		ans[p[i].id]=cur[p[i].k];
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}