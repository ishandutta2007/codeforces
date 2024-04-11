#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,h[N],mx=1000000000;

int tot=1;
struct node {int ls,rs,sz,sum;} t[N*32];
void ins(int p,int l,int r,int x) {
	int mid=(l+r)/2;
	if(l==r) {t[p].sz++,t[p].sum+=x;return;}
	if(x<=mid) ins(t[p].ls?t[p].ls:t[p].ls=++tot,l,mid,x);
	else ins(t[p].rs?t[p].rs:t[p].rs=++tot,mid+1,r,x);
	t[p].sz=t[t[p].ls].sz+t[t[p].rs].sz,
	t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
void del(int p,int l,int r,int x) {
	int mid=(l+r)/2;
	if(l==r) {t[p].sz--,t[p].sum-=x;return;}
	if(x<=mid) del(t[p].ls,l,mid,x);
	else del(t[p].rs,mid+1,r,x);
	t[p].sz=t[t[p].ls].sz+t[t[p].rs].sz,
	t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
double query(int x) {
	int l=0,r=mx,p=1,ssz=0,ssum=0;
	while(l!=r) {
		double mid=(l+r)/2;
		if(t[p].ls&&(ssz+t[t[p].ls].sz)*(mid+0.9999)-ssum-t[t[p].ls].sum>=x) p=t[p].ls,r=(l+r)/2;
		else {
			if(t[p].ls) ssz+=t[t[p].ls].sz, ssum+=t[t[p].ls].sum;
			p=t[p].rs, l=(l+r)/2+1;
		}
	}
	return min(1.*(ssum+t[p].sum+x)/(ssz+t[p].sz),1.*(ssum+x)/ssz);
}

signed main() {
	n=read(), m=read();
	rep(i,1,n) ins(1,0,mx,h[i]=read());
	rep(i,1,m) {
		int opt=read(),p=read();
		if(opt==1) del(1,0,mx,h[p]), ins(1,0,mx,h[p]=read());
		else printf("%.5lf\n",query(p));
	}
	return 0;
}