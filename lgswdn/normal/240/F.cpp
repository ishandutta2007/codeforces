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

int n,m,cnt[29];
char s[N];

struct segtree {
	struct node {int l,r,cnt,tag;} t[N*4];
	void build(int p,int l,int r,char c) {
		int mid=((t[p].l=l)+(t[p].r=r))/2;
		if(l==r) {t[p].cnt=(s[l]==c); return;}
		build(p*2,l,mid,c), build(p*2+1,mid+1,r,c);
		t[p].cnt=t[p*2].cnt+t[p*2+1].cnt;
	}
	void pushdown(int p) {
		t[p*2].tag=t[p*2+1].tag=t[p].tag;
		if(t[p].tag==-1) t[p*2].cnt=t[p*2+1].cnt=0;
		else {
			t[p*2].cnt=t[p*2].r-t[p*2].l+1;
			t[p*2+1].cnt=t[p*2+1].r-t[p*2+1].l+1;
		}
		t[p].tag=0;
	}
	void modify(int p,int x,int y,int k) {
		int l=t[p].l, r=t[p].r, mid=(l+r)/2;
		if(l==x&&r==y) {t[p].cnt=(k>0?r-l+1:0),t[p].tag=k; return;}
		if(t[p].tag) pushdown(p);
		if(y<=mid) modify(p*2,x,y,k);
		else if(x>mid) modify(p*2+1,x,y,k);
		else modify(p*2,x,mid,k), modify(p*2+1,mid+1,y,k);
		t[p].cnt=t[p*2].cnt+t[p*2+1].cnt;
	}
	int query(int p,int x,int y) {
		int l=t[p].l, r=t[p].r, mid=(l+r)/2;
		if(l==x&&r==y) return t[p].cnt;
		if(t[p].tag) pushdown(p);
		if(y<=mid) return query(p*2,x,y);
		else if(x>mid) return query(p*2+1,x,y);
		else return query(p*2,x,mid)+query(p*2+1,mid+1,y);
	}
}st[29];

void print(int l=1,int r=n) {
	rep(i,l,r) 
		rep(j,0,25)
			if(st[j].query(1,i,i)) {putchar(j+'a');break;}
	puts(""); 
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	rep(i,0,25) st[i].build(1,1,n,i+'a');
	rep(i,1,m) {
		int l=read(), r=read(), odd=0;
		rep(i,0,25) cnt[i]=st[i].query(1,l,r), odd+=cnt[i]%2;
		if(odd>1) continue;
		rep(i,0,25) st[i].modify(1,l,r,-1);
		int pos=0;
		rep(i,0,25) if(cnt[i]>1) {
			int ycnt=cnt[i];
			cnt[i]/=2;
			st[i].modify(1,l+pos,l+pos+cnt[i]-1,1);
			st[i].modify(1,r-pos-cnt[i]+1,r-pos,1);
			pos+=cnt[i];
			cnt[i]=ycnt;
		}
		if(odd) {
			rep(i,0,25) if(cnt[i]%2==1) {
				st[i].modify(1,l+pos,l+pos,1);
			}
		}
	}
	print();
	return 0;
}