#include<cstdio>
#include<algorithm>
#define MAXN 100000
using namespace std;
#define MOD 1000000007
typedef long long LL;
int n,m,a[MAXN+10],inv2=MOD/2+1;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int quick_pow(int a,int b){
	int ret(1);
	while(b){
		if(b&1)
			ret=1ll*ret*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return ret;
}
struct data{
	int a,b; //a+bsqrt(5)
	inline data(){
	}
	inline data(int a,int b=0):a(a),b(b){
	}
	inline data operator + (const data &x)const{
		return data((a+x.a)%MOD,(b+x.b)%MOD);
	}
	inline data & operator +=(const data &x){
		return *this=*this+x;
	}
	inline data operator - (const data &x)const{
		return data((a-x.a+MOD)%MOD,(b-x.b+MOD)%MOD);
	}
	inline data & operator -=(const data &x){
		return *this=*this-x;
	}
	inline data operator * (const data &x)const{
		return data((1ll*a*x.a+5ll*b*x.b)%MOD,(1ll*a*x.b+1ll*b*x.a)%MOD);
	}
	inline data & operator *= (const data &x){
		return *this=*this*x;
	}
	inline data operator / (const data &x)const{
		static data ret;
		int inv;
		ret=*this*data(x.a,MOD-x.b);
		inv=quick_pow(((1ll*x.a*x.a-5ll*x.b*x.b)%MOD+MOD)%MOD,MOD-2);
		ret.a=1ll*ret.a*inv%MOD;
		ret.b=1ll*ret.b*inv%MOD;
		return ret;
	}
	inline data & operator /= (const data &x){
		return *this=*this/x;
	}
}ba(inv2,inv2),bb(inv2,MOD-inv2);
data quick_pow(data a,LL b){
	data ret(1);
	while(b){
		if(b&1)
			ret*=a;
		a*=a;
		b>>=1;
	}
	return ret;
}
struct node{
	data a,b,taga,tagb;
}tree[MAXN*4+10];
void update(int i){
	tree[i].a=tree[i<<1].a+tree[(i<<1)|1].a;
	tree[i].b=tree[i<<1].b+tree[(i<<1)|1].b;
}
void push_down(int i){
	tree[i<<1].a*=tree[i].taga;
	tree[i<<1].b*=tree[i].tagb;
	tree[(i<<1)|1].a*=tree[i].taga;
	tree[(i<<1)|1].b*=tree[i].tagb;
	tree[i<<1].taga*=tree[i].taga;
	tree[i<<1].tagb*=tree[i].tagb;
	tree[(i<<1)|1].taga*=tree[i].taga;
	tree[(i<<1)|1].tagb*=tree[i].tagb;
	tree[i].taga=tree[i].tagb=1;
}
void build(int i,int l,int r){
	tree[i].taga=tree[i].tagb=1;
	if(l==r){
		tree[i].a=quick_pow(ba,a[l]),tree[i].b=quick_pow(bb,a[l]);
		return;
	}
	int mid((l+r)>>1);
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
	update(i);
}
void insert(int i,int l,int r,int ll,int rr,int d){
	if(ll<=l&&r<=rr){
		data da=quick_pow(ba,d),db=quick_pow(bb,d);
		tree[i].taga*=da,tree[i].tagb*=db;
		tree[i].a*=da;
		tree[i].b*=db;
		return;
	}
	if(ll>r||rr<l)
		return;
	int mid((l+r)>>1);
	push_down(i);
	insert(i<<1,l,mid,ll,rr,d);
	insert((i<<1)|1,mid+1,r,ll,rr,d);
	update(i);
}
data get_sum(int i,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr)
		return tree[i].a-tree[i].b;
	if(ll>r||rr<l)
		return 0;
	int mid((l+r)>>1);
	push_down(i);
	return get_sum(i<<1,l,mid,ll,rr)+get_sum((i<<1)|1,mid+1,r,ll,rr);
}
void read(){
	Read(n),Read(m);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i]);
	build(1,1,n);
}
void solve(){
	int p,l,r,x;
	while(m--){
		Read(p),Read(l),Read(r);
		if(p==1){
			Read(x);
			insert(1,1,n,l,r,x);
		}
		else{
			data ret=get_sum(1,1,n,l,r);
			ret/=data(0,1);
			printf("%d\n",ret.a);
		}
	}
}
int main()
{
	read();
	solve();
}