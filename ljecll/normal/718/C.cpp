#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
const int N=1e5+5;
const ll M=1e9+7;
const ll inv2=5e8+4;
using namespace std;

struct Num{
	ll a,b;
	Num():a(1),b(0){}
	Num(ll x,ll y):a(x%M),b(y%M){}
	Num operator +(const Num &B)const{
		return Num(a+B.a,b+B.b);
	}
	Num operator *(const Num &B)const{
		return Num(a*B.a+b*B.b*5,a*B.b+b*B.a);
	}
	Num operator ^(int t)const{
		Num A=(*this),B(1,0);
		while(t){if(t&1)B=B*A;A=A*A;t>>=1;}
		return B;
	}
}eA(inv2,inv2),eB(inv2,-inv2),tr[2][N<<2],lz[2][N<<2];

void pushup(int i,int x){
	tr[i][x]=tr[i][x<<1]+tr[i][x<<1|1];
}
void pushdown(int i,int x){
	tr[i][x<<1]=tr[i][x<<1]*lz[i][x];
	tr[i][x<<1|1]=tr[i][x<<1|1]*lz[i][x];
	lz[i][x<<1]=lz[i][x<<1]*lz[i][x];
	lz[i][x<<1|1]=lz[i][x<<1|1]*lz[i][x];
	lz[i][x].a=1,lz[i][x].b=0;
}
#define ls l,r,L,L+R>>1,x<<1
#define rs l,r,(L+R>>1)+1,R,x<<1|1
void add(int l,int r,int L,int R,int x,int i,Num ad){
	if(l>R||L>r)return;
	if(l<=L&&R<=r){
		tr[i][x]=tr[i][x]*ad;
		lz[i][x]=lz[i][x]*ad;
		return;
	}
	if(L!=R) pushdown(i,x);
	add(ls,i,ad);add(rs,i,ad);
	pushup(i,x);
}
ll query(int l,int r,int L,int R,int x){
	if(l>R||L>r)return 0;
	if(l<=L&&R<=r)return (tr[0][x].b-tr[1][x].b)%M;
	if(L!=R)pushdown(0,x),pushdown(1, x);
	return (query(ls)+query(rs))%M;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		add(i,i,1,n,1,0,eA^a);
		add(i,i,1,n,1,1,eB^a);
	}
	for(int i=1,t,l,r,x;i<=m;i++){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			scanf("%d",&x);
			add(l,r,1,n,1,0,eA^x);
			add(l,r,1,n,1,1,eB^x);
		}
		else printf("%lld\n",query(l,r,1,n,1));
	}
	return 0;
}