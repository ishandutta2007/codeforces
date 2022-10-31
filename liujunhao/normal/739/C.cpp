#include<cstdio>
#include<algorithm>
#define MAXN 300000
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
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
typedef long long LL;
LL n,a[MAXN+10],d[MAXN+10],m;
struct node{
	int mx,lmx,rmx;
}tree[MAXN*4+10];
inline int sign(LL x){
	if(x<0)
		return -1;
	if(x>0)
		return 1;
	return 0;
}
void update(int i,int l,int r){
	int mid((l+r)>>1);
	tree[i].lmx=tree[i<<1].lmx;
	tree[i].rmx=tree[(i<<1)|1].rmx;
	int t=0;
	if(sign(d[mid])>=sign(d[mid+1]))
		t=tree[i<<1].rmx+tree[(i<<1)|1].lmx;
	tree[i].mx=max(max(tree[i<<1].mx,tree[(i<<1)|1].mx),t);
	if(tree[i<<1].rmx==mid-l+1)
		tree[i].lmx=max(tree[i].lmx,t);
	if(tree[(i<<1)|1].lmx==r-mid)
		tree[i].rmx=max(tree[i].rmx,t);
}
void build(int i,int l,int r){
	if(l==r){
		if(d[l])
			tree[i].mx=tree[i].lmx=tree[i].rmx=1;
		return;
	}
	int mid((l+r)>>1);
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
	update(i,l,r);
}
void insert(int i,int l,int r,int p){
	if(l==r){
		if(d[l])
			tree[i].lmx=tree[i].rmx=tree[i].mx=1;
		else
			tree[i].lmx=tree[i].rmx=tree[i].mx=0;
		return;
	}
	int mid((l+r)>>1);
	if(p<=mid)
		insert(i<<1,l,mid,p);
	else
		insert((i<<1)|1,mid+1,r,p);
	update(i,l,r);
}
void read(){
	Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i]);
	for(i=1;i<n;i++)
		d[i]=a[i+1]-a[i];
	if(n!=1)
		build(1,1,n-1);
}
void solve(){
	int l,r,dd;
	Read(m);
	while(m--){
		Read(l),Read(r),Read(dd);
		if(n==1){
			puts("1");
			continue;
		}
		d[l-1]+=dd,d[r]-=dd;
		if(l>1)
			insert(1,1,n-1,l-1);
		if(r<n)
			insert(1,1,n-1,r);
		printf("%d\n",tree[1].mx+1);
	}
}
int main()
{
	read();
	solve();
}