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

int n,ans[N];
struct dom {int id,x,h;} a[N];
bool cmp(const dom &x,const dom &y) {return x.x<y.x;}

struct node {int val;} t[N<<2];
void add(int p,int l,int r,int x,int val) {
	if(l==r) {t[p].val=val; return;}
	int mid=(l+r)/2;
	if(x<=mid) add(p*2,l,mid,x,val);
	else add(p*2+1,mid+1,r,x,val);
	t[p].val=max(t[p*2].val,t[p*2+1].val);
}
int query(int p,int l,int r,int x,int y) {
	if(x==l&&y==r) return t[p].val;
	int mid=(l+r)/2;
	if(y<=mid) return query(p*2,l,mid,x,y);
	else if(x>mid) return query(p*2+1,mid+1,r,x,y);
	else return max(query(p*2,l,mid,x,mid),query(p*2+1,mid+1,r,mid+1,y));
}

int main() {
	n=read();
	rep(i,1,n) a[i].x=read(), a[i].h=read(), a[i].id=i;
	sort(a+1,a+n+1,cmp);
	add(1,1,n,n,1+n);
	ans[a[n].id]=1;
	per(i,n-1,1) {
		int l=i+1,r=n,g=0;
		while(l<=r) {
			int mid=(l+r)/2;
			if(a[i].x+a[i].h-1>=a[mid].x) g=mid, l=mid+1;
			else r=mid-1;
		}
		if(g) ans[a[i].id]=query(1,1,n,i+1,g)-i;
		else ans[a[i].id]=1;
		add(1,1,n,i,ans[a[i].id]+i);
	}
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}