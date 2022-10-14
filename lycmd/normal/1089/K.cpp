#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=4000010;
int q,res,n=1000000,x,y,a[N],b[N],tr[N],s[N];
char op;
void update(int x){
	s[x]=s[ls(x)]+s[rs(x)];
	tr[x]=max(tr[ls(x)]+s[rs(x)],tr[rs(x)]);
}
void modify(int x,int l,int r,int p,int k){
	if(l==r)
		return s[x]+=k,tr[x]=l+s[x],void();
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(ls(x),l,mid,p,k);
	else
		modify(rs(x),mid+1,r,p,k);
	update(x);
}
void query(int x,int l,int r,int p){
	if(r<=p)
		return res=max(res+s[x],tr[x]),void();
	int mid=(l+r)>>1;
	query(ls(x),l,mid,p);
	if(p>mid)
		query(rs(x),mid+1,r,p);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>q;
	for(int i=1;i<=q;i++){
		switch(cin>>op>>x,op){
			case'+':
				cin>>y,modify(1,1,n,x,y),a[i]=x,b[i]=y;break;
			case'-':
				modify(1,1,n,a[x],-b[x]);break;
			case'?':
				res=0,query(1,1,n,x),cout<<max(res-x,0ll)<<"\n";break;
		}
	}
}