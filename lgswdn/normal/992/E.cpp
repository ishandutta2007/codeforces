#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,q,a[N];
long long s[N];

struct node {int l,r;long long x,tag;} t[N*4];
void build(int p,int l,int r) {
	int mid=((t[p].l=l)+(t[p].r=r))/2;
	if(l==r) {t[p].x=s[l]; return;}
	build(p*2,l,mid), build(p*2+1,mid+1,r);
	t[p].x=max(t[p*2].x,t[p*2+1].x); 
}
void pushdown(int p) {
	t[p*2].tag+=t[p].tag, t[p*2+1].tag+=t[p].tag;
	t[p*2].x+=t[p].tag, t[p*2+1].x+=t[p].tag;
	t[p].tag=0;
}
void add(int p,int x,int y,int k) {
	int l=t[p].l, r=t[p].r, mid=(l+r)/2;
	if(l==x&&r==y) {t[p].x+=k,t[p].tag+=k; return;}
	pushdown(p);
	if(y<=mid) add(p*2,x,y,k);
	else if(x>mid) add(p*2+1,x,y,k);
	else add(p*2,x,mid,k), add(p*2+1,mid+1,y,k);
	t[p].x=max(t[p*2].x,t[p*2+1].x);
}
int query(int p,long long k) {
	if(t[p].l==t[p].r) return t[p].x>=k?p:-1;
	pushdown(p);
	if(t[p*2].x>=k) return query(p*2,k);
	else if(t[p*2+1].x>=k) return query(p*2+1,k);
	else return -1;
}

int main() {
	n=read(), q=read();
	rep(i,1,n) a[i]=read(), s[i]=s[i-1]+a[i];
	build(1,1,n);
	rep(i,1,q) {
		int pos=read(), val=read();
		add(1,pos,n,val-a[pos]);
		a[pos]=val;
		int k=1;long long sk=a[1];
		while(k) {
			//cout<<k<<" "<<sk<<endl;
			int p=query(1,2*sk);
			if(p==-1) {puts("-1");break;}
			sk=t[p].x, k=t[p].l;
			if(2*a[k]==sk) {printf("%d\n",k);break;}
		}
	}
	return 0;
}