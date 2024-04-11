#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=1200010,K=300001;
int n,m,k,cur,ans[N],ex[N],ey[N],pre[N];
vector<int>tr[N];
map<pair<int,int>,int>ord;
struct dsu{
	static int const N=600010;
	int f[N],h[N],cx[N],cy[N];
	stack<array<int,5> >s;
	void init(int n=N-1){
		for(int i=1;i<=n;i++)
			f[i]=i,h[i]=1,cx[i]=i<=K,cy[i]=i>K;
	}
	int find(int x){
		return x^f[x]?find(f[x]):x;
	} 
	int check(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fx=find(x),fy=find(y);
		if(fx==fy)
			return;
		if(h[fx]>h[fy])
			swap(fx,fy);
		s.push({fx,h[fx]==h[fy],cx[fx],cy[fx],cur});
		cur-=cx[fx]*cy[fx]+cx[fy]*cy[fy];
		h[fy]+=h[fx]==h[fy],f[fx]=fy,cx[fy]+=cx[fx],cy[fy]+=cy[fx];
		cur+=cx[fy]*cy[fy];
	}
	void undo(){
		auto t=s.top();s.pop();
		int x=t[0],&y=f[x];
		h[y]-=t[1],cx[y]-=t[2],cy[y]-=t[3],y=x,cur=t[4];
	}
};
dsu g;
void modify(int x,int l,int r,int ql,int qr,int i){
	if(ql>qr)
		return;
	if(ql<=l&&r<=qr)
		return tr[x].push_back(i);
	int mid=(l+r)>>1;
	if(ql<=mid)
		modify(ls(x),l,mid,ql,qr,i);
	if(qr>mid)
		modify(rs(x),mid+1,r,ql,qr,i);
}
void solve(int x,int l,int r){
	int t=g.s.size(),mid=(l+r)>>1;
	for(int i:tr[x])
		g.merge(ex[i],ey[i]+K);
	if(l==r)
		ans[l]=cur;
	else
		solve(ls(x),l,mid),
		solve(rs(x),mid+1,r);
	while(g.s.size()>t)
		g.undo();
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>k,g.init();
	for(int i=1,x,y;i<=k;i++){
		cin>>x>>y;
		if(!ord.count({x,y}))
			ex[++m]=x,ey[m]=y,ord[{x,y}]=m;
		int t=ord[{x,y}];
		if(pre[t])
			modify(1,1,k,pre[t],i-1,t),pre[t]=0;
		else
			pre[t]=i;
	}
	for(int i=1;i<=m;i++)
		if(pre[i])
			modify(1,1,k,pre[i],k,i);
	solve(1,1,k);
	for(int i=1;i<=k;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}