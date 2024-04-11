#include<bits/stdc++.h>
#define ll long long
#define inf 1010000000
#define infll 1010000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 400009
using namespace std;

int n,m; char ch[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
struct node{
	int u,v,len,l0,l1,r0,r1;
	void mdy(char x){
		len=l0=l1=r0=r1=-inf; u=v=0;
		if (x=='(') v=1; else if (x==')') u=1;
		else l0=l1=r0=r1=0;
	}
}T[N<<2];
void maintain(int k){
	node x=T[k<<1],y=T[k<<1|1];
	T[k].len=max(x.r0+y.l1,x.r1+y.l0);
	T[k].len=max(T[k].len,max(x.len,y.len));
	if (x.v<y.u){ T[k].u=x.u-x.v+y.u; T[k].v=y.v; }
	else{ T[k].u=x.u; T[k].v=y.v-y.u+x.v; }
	T[k].l0=max(x.l0,x.v-x.u+y.l0);
	T[k].l1=max(x.l1,max(x.u-x.v+y.l1,x.u+x.v+y.l0));
	T[k].r0=max(y.r0,y.u-y.v+x.r0);
	T[k].r1=max(y.r1,max(y.v-y.u+x.r1,y.u+y.v+x.r0));
} 
void build(int k,int l,int r){
	if (l==r){
		T[k].mdy(ch[l]); return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
	maintain(k);
}
void mdy(int k,int l,int r,int x){
	if (l==r){
		T[k].mdy(ch[l]); return;
	}
	int mid=l+r>>1;
	if (x<=mid) mdy(k<<1,l,mid,x); else mdy(k<<1|1,mid+1,r,x);
	maintain(k);
}
int main(){
	scanf("%d%d%s",&n,&m,ch+1);
	int i; n<<=1;
	for (i=n; i; i--) ch[i<<1]=ch[i];
	for (i=0; i<n; i++) ch[i<<1|1]='?';
	n<<=1;
	build(1,1,n);
	printf("%d\n",T[1].len);
	while (m--){
		int x,y; scanf("%d%d",&x,&y); x<<=1; y<<=1;
		swap(ch[x],ch[y]);
		mdy(1,1,n,x); mdy(1,1,n,y);
		printf("%d\n",T[1].len);	
	}
	return 0;
}