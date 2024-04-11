#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=2e5+5,MAXM=1e6+5;
int n,q,a[MAXN],b[MAXN];
int top,stk[MAXN],lc[MAXN],rc[MAXN],rg[MAXN][2];
vector<pr> dv[MAXN],ad[MAXN],qu[MAXN];
struct node{
	int l1,l2,r1,len;
};
vector<node> de[MAXN];
inline void Add(int l1,int l2,int r1,int r2){
	//printf("Add %d %d %d %d\n",l1,l2,r1,r2);
	ad[r1].emplace_back(l1,l2);
	de[r2+1].push_back(node{l1,l2,r1,r2-r1+1});
}
int rt;
void Dfs(int u){
	if(lc[u]) Dfs(lc[u]),rg[u][0]=rg[lc[u]][0];
	else rg[u][0]=u;
	if(rc[u]) Dfs(rc[u]),rg[u][1]=rg[rc[u]][1];
	else rg[u][1]=u;
	int x=rg[u][0],y=rg[u][1];
	static vector<pr> tmp,res;
	for(pr i:dv[a[u]]){
		int l=i.first,r=i.second;
		if(l>r) swap(l,r);
		if(l<x||r>y) continue;
		l=min(l,u);
		r=max(r,u);
		tmp.emplace_back(l,r);
	}
	//printf("Dfs %d x %d y %d\n",u,x,y);
	if(tmp.empty()) return ;
	sort(tmp.begin(),tmp.end());
	for(pr i:tmp){
		int l=i.first,r=i.second;
		if(!res.empty()&&res.back().first==l) continue;
		while(!res.empty()&&res.back().second>=r) res.pop_back();
		res.push_back(i);
	}
	for(int i=0; i<res.size(); i++)
		Add(x,res[i].first,res[i].second,i+1==res.size()?y:res[i+1].second-1);
	tmp.clear();
	res.clear();
	return ;
}
struct BIT{
	ll s[MAXN];
	inline ll query(int x){
		ll res=0;
		for(int i=x; i; i&=i-1)
			res+=s[i];
		return res;
	}
	inline void add(int x,ll y){
		for(int i=x; i<=n; i+=i&-i)
			s[i]+=y;
	}
	inline void Modify(int x,int y,ll v){
		add(x,v);
		add(y+1,-v);
	}
}b1,bl,br,blr;
void Modify(int l1,int l2,int r1,int c){
	//printf("%d %d %d c %d\n",l1,l2,r1,c);
	b1.Modify(l1,l2,(1ll-r1)*(1+l2)*c);
	bl.Modify(l1,l2,(r1-1)*c);
	br.Modify(l1,l2,(1+l2)*c);
	blr.Modify(l1,l2,-c);
	b1.Modify(1,l1-1,(l2-l1+1ll)*(1-r1)*c);
	br.Modify(1,l1-1,(l2-l1+1)*c);
}
void Mdf(int l1,int l2,int len){
	b1.Modify(l1,l2,(l2+1ll)*len);
	bl.Modify(l1,l2,-len);
	b1.Modify(1,l1-1,len*(l2-l1+1ll));
}
ll Query(int l,int r){
	ll res=0;
	res+=b1.query(l);
	res+=bl.query(l)*l;
	res+=br.query(l)*r;
	res+=blr.query(l)*l*r;
	return res;
}
ll ans[MAXM];
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++){
		scanf("%d",a+i);
		b[a[i]]=i;
		while(top&&a[stk[top]]<a[i]){
			rc[stk[top]]=lc[i];
			lc[i]=stk[top];
			top--;
		}
		stk[++top]=i;
	}
	while(top){
		rc[stk[top]]=rt;
		rt=stk[top];
		top--;
	}
	for(int i=1; i*i<=n; i++)
		for(int j=i+1; i*j<=n; j++)
			dv[i*j].emplace_back(b[i],b[j]);
	Dfs(rt);
	for(int i=1; i<=q; i++){
		int l,r;
		scanf("%d%d",&l,&r);
		qu[r].emplace_back(l,i);
	}
	for(int i=1; i<=n; i++){
		for(pr j:ad[i]) Modify(j.first,j.second,i,1);
		for(node j:de[i]) Modify(j.l1,j.l2,j.r1,-1),Mdf(j.l1,j.l2,j.len);
		for(pr j:qu[i]) ans[j.second]=Query(j.first,i);
	}
	for(int i=1; i<=q; i++)
		printf("%lld\n",ans[i]);
	return 0;
}