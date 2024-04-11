#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=12000010,K=2000000;
int n,r,ans,tr[N],lt[N];
pair<int,int>p[N];
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
void ins(int x,int y){
	modify(1,-K,K,p[x].second,min(p[x].second+r,K),y);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>r,r<<=1;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		p[i]={x+y,x-y};
	}
	sort(p+1,p+1+n);
	for(int i=1,j=1;i<=n;i++){
		ins(i,1);
		for(;p[i].first-p[j].first>r;j++)ins(j,-1);
		ans=max(ans,tr[1]);
	}
	cout<<ans<<"\n";
}