#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=800010;
int n,m,ans,a[N],tr[N],lt[N];
vector<pair<int,int> >p[N];
void update(int x){
	tr[x]=max(tr[ls(x)],tr[rs(x)]);
}
void add(int x,int k){
	tr[x]+=k,lt[x]+=k;
}
void download(int x){
	int&t=lt[x];
	if(!t)return;
	add(ls(x),t),add(rs(x),t),t=0;
}
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr){
		add(x,k);
		return;
	}
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)modify(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
int query(){
	return tr[1];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(m--){
		int a,b,c;cin>>a>>b>>c;
		p[b].push_back({a,c});
	}
	for(int i=1;i<=n;i++){
		modify(1,1,n,i,i,ans);
		modify(1,1,n,1,i,-a[i]);
		for(auto j:p[i])
			modify(1,1,n,1,j.first,j.second);
		ans=max(ans,query());
	}
	cout<<ans<<"\n";
}