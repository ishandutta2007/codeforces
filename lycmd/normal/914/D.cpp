#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=2333333;
int n,q,cnt,a[N],tr[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void update(int x){
	tr[x]=gcd(tr[ls(x)],tr[rs(x)]);
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int p,int k){
	if(l==r){
		tr[x]=k;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)modify(ls(x),l,mid,p,k);
	else modify(rs(x),mid+1,r,p,k);
	update(x);
}
void query(int x,int l,int r,int ql,int qr,int k){
	if(tr[x]%k==0||cnt>1)
		return;
	if(l==r){
		cnt++;
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)query(ls(x),l,mid,ql,qr,k);
	if(qr>mid)query(rs(x),mid+1,r,ql,qr,k);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for(cin>>q;q--;){
		int op,l,r,x;
		cin>>op>>l>>r;
		if(op<2){
			cin>>x,cnt=0,query(1,1,n,l,r,x);
			cout<<(cnt>1?"NO\n":"YES\n");
		}else{
			modify(1,1,n,l,r);
		}
	}
}