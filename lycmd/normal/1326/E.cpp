#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=1200010;
int n,a[N],p[N],q[N],tr[N],lt[N];
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
	if(ql<=l&&r<=qr)
		return add(x,k);
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)
		modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)
		modify(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[a[i]]=i;
	for(int i=1;i<=n;i++)
		cin>>q[i];
	int res=n;
	modify(1,1,n,1,p[n],1);
	cout<<n<<" ";
	for(int i=1;i<n;cout<<res<<" ",i++)
		for(modify(1,1,n,1,q[i],-1);tr[1]<1;)
			modify(1,1,n,1,p[--res],1);
	cout<<"\n";
}