#include<bits/stdc++.h>
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

int n,a[N],p[N],pr[N];
bool vst[N];

struct node {int val;} t[N<<2];
void modify(int p,int l,int r,int pos,int x) {
	if(l==r) {t[p].val=x; return;}
	int mid=(l+r)/2;
	if(pos<=mid) modify(p*2,l,mid,pos,x);
	else modify(p*2+1,mid+1,r,pos,x);
	t[p].val=min(t[p*2].val,t[p*2+1].val);
}
int query(int p,int l,int r,int x,int y) {
	if(l==x&&r==y) return t[p].val;
	int mid=(l+r)/2;
	if(y<=mid) return query(p*2,l,mid,x,y);
	else if(x>mid) return query(p*2+1,mid+1,r,x,y);
	else return min(query(p*2,l,mid,x,mid),query(p*2+1,mid+1,r,mid+1,y));
}

signed main() {
	n=read();
	rep(i,1,n) {
		a[i]=read();
		if(a[i]!=1) vst[1]=1;
		p[i]=pr[a[i]];
		pr[a[i]]=i;
		if(a[i]>1&&query(1,1,n,1,a[i]-1)>p[i]) vst[a[i]]=1;
		modify(1,1,n,a[i],i);
	}
	rep(i,1,n) if(query(1,1,n,1,i)>pr[i+1]) vst[i+1]=1;
	rep(i,1,n+2) if(!vst[i]) {printf("%d\n",i); break;}
	return 0;
}