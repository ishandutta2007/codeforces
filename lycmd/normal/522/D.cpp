#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=2000010,INF=0x3f3f3f3f;
int n,q,a[N],pre[N],cur[N],ans[N],tr[N];
vector<int>b;
vector<array<int,3> >p;
void update(int x){
	tr[x]=min(tr[ls(x)],tr[rs(x)]);
}
void modify(int x,int l,int r,int p,int k){
	if(l==r){
		tr[x]=k;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(ls(x),l,mid,p,k);
	else
		modify(rs(x),mid+1,r,p,k);
	update(x); 
}
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	int mid=(l+r)>>1,res=INF;
	if(ql<=mid)
		res=min(res,query(ls(x),l,mid,ql,qr));
	if(qr>mid)
		res=min(res,query(rs(x),mid+1,r,ql,qr));
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i],b.push_back(a[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1,
		pre[i]=cur[a[i]],cur[a[i]]=i;
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		p.push_back({r,l,i});
	}
	sort(p.begin(),p.end());
	memset(tr,INF,sizeof tr);
	int lst=0;
	for(auto i:p){
		for(int j=lst+1;j<=i[0];j++)
			if(pre[j])
				modify(1,1,n,pre[j],j-pre[j]);
		ans[i[2]]=query(1,1,n,i[1],lst=i[0]);
	}
	for(int i=1;i<=q;i++)
		cout<<(ans[i]<INF?ans[i]:-1)<<"\n";
}