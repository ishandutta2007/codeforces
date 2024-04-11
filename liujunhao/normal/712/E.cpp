#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100000
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF){
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
	}
}
int n,m;
double val[MAXN+10];
struct node{
	double f1,f2;
	inline node(){
	}
	inline node(double f1,double f2):f1(f1),f2(f2){
	}
}tree[(1<<18)+10];
void update(int i){
	tree[i].f1=tree[i<<1].f1*tree[(i<<1)|1].f1/(1-(1-tree[(i<<1)|1].f1)*tree[i<<1].f2);
	tree[i].f2=tree[(i<<1)|1].f2+(1-tree[(i<<1)|1].f2)*tree[(i<<1)|1].f1*tree[i<<1].f2/(1-tree[i<<1].f2*(1-tree[(i<<1)|1].f1));
}
node merge_ans(const node &l,const node &r){
	double f1,f2;
	f1=l.f1*r.f1/(1-(1-r.f1)*l.f2);
	f2=r.f2+(1-r.f2)*r.f1*l.f2/(1-l.f2*(1-r.f1));
	return node(f1,f2);
}
void insert(int i,int l,int r,int p,double val){
	if(l==r){
		tree[i].f1=tree[i].f2=val;
		return;
	}
	int mid((l+r)>>1);
	if(p<=mid)
		insert(i<<1,l,mid,p,val);
	else
		insert((i<<1)|1,mid+1,r,p,val);
	update(i);
}
node get_val(int i,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr)
		return tree[i];
	int mid((l+r)>>1);
	node ret1,ret2;
	if(ll<=mid)
		ret1=get_val(i<<1,l,mid,ll,rr);
	if(rr>mid)
		ret2=get_val((i<<1)|1,mid+1,r,ll,rr);
	if(rr<=mid)
		return ret1;
	if(ll>mid)
		return ret2;
	return merge_ans(ret1,ret2);
}
void build(int i,int l,int r){
	if(l==r){
		tree[i].f1=tree[i].f2=val[l];
		return;
	}
	int mid((l+r)>>1);
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
	update(i);
}
void read(){
	Read(n),Read(m);
	int i,a,b;
	for(i=1;i<=n;i++){
		Read(a),Read(b);
		val[i]=1.0*a/b;
	}
	build(1,1,n);
}
void solve(){
	int p,l,a,b,r;
	while(m--){
		Read(p);
		if(p==1){
			Read(l),Read(a),Read(b);
			insert(1,1,n,l,1.*a/b);
		}
		else{
			Read(l),Read(r);
			printf("%.10lf\n",get_val(1,1,n,l,r).f1);
		}
	}
}
int main()
{
	read();
	solve();
}