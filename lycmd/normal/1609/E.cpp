#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=2333333;
int n,q,a[N],b[N],c[N],ab[N],bc[N],abc[N];
string s;
inline void update(int x){
	a[x]=a[ls(x)]+a[rs(x)];
	b[x]=b[ls(x)]+b[rs(x)];
	c[x]=c[ls(x)]+c[rs(x)];
	ab[x]=max(a[ls(x)]+ab[rs(x)],ab[ls(x)]+b[rs(x)]);
	bc[x]=max(b[ls(x)]+bc[rs(x)],bc[ls(x)]+c[rs(x)]);
	abc[x]=max(a[ls(x)]+abc[rs(x)],max(ab[ls(x)]+bc[rs(x)],abc[ls(x)]+c[rs(x)]));
}
inline void build(int x,int l,int r){
	if(l==r){
		a[x]=b[x]=c[x]=ab[x]=bc[x]=abc[x]=1;
		switch(s[l]){
			case'a':a[x]--;break;
			case'b':b[x]--;break;
			case'c':c[x]--;break;
		}
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
inline void update(int x,int l,int r,int p,int op){
	if(l==r){
		a[x]=b[x]=c[x]=ab[x]=bc[x]=abc[x]=1;
		switch(op){
			case'a':a[x]--;break;
			case'b':b[x]--;break;
			case'c':c[x]--;break;
		}
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)update(ls(x),l,mid,p,op);
	else update(rs(x),mid+1,r,p,op);
	update(x);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q>>s,s=" "+s;
	build(1,1,n);
	while(q--){
		int p;char c;
		cin>>p>>c;
		update(1,1,n,p,c);
		cout<<n-abc[1]<<"\n";
	}
}