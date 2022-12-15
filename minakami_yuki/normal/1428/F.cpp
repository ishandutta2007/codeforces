#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+10;
const LL INF=1e18;
const LL P=1e9+7;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
int n,K;
char s[N];
struct node{
	int l,r;
	LL laz;
	LL mn;
	LL s;
}d[N<<2];

void build(int l,int r,int id){
	d[id].l=l;d[id].r=r;
	d[id].laz=d[id].mn=d[id].s=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	return;
}

#define ls id<<1
#define rs id<<1|1

void pushdown(int id){
	if(d[id].l==d[id].r) return;
	if(d[id].laz==0) return;
	d[ls].mn=d[id].laz;d[ls].s=d[id].laz*(LL)(d[ls].r-d[ls].l+1);
	d[rs].mn=d[id].laz;d[rs].s=d[id].laz*(LL)(d[rs].r-d[rs].l+1);
	d[ls].laz=d[id].laz;d[rs].laz=d[id].laz;d[id].laz=0;
}

int ask(int id,LL w){
	pushdown(id);
	if(d[id].l==d[id].r) return d[id].l;
	if(d[rs].mn<=w) return ask(rs,w);
	else return ask(ls,w);
}

void pushup(int id){
	if(d[id].l==d[id].r) return;
	d[id].mn=min(d[ls].mn,d[rs].mn);
	d[id].s=d[ls].s+d[rs].s;
}

void C(int l,int r,int id,LL w){
	pushdown(id);
	if(d[id].l==l&&d[id].r==r){
		d[id].laz=w;
		d[id].mn=w;
		d[id].s=w*(LL)(r-l+1);
		return;
	}
	if(d[ls].r>=r) C(l,r,ls,w);
	else if(l>d[ls].r) C(l,r,rs,w);
	else {
		C(l,d[ls].r,ls,w);
		C(d[rs].l,r,rs,w);
	} 
	pushup(id);
}

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	LL now=0;
	build(1,n,1);
	LL ans=0;
	int R;
	for(int i=n;i>=1;--i){
		if(s[i]=='0'){
			if(now>0){
				for(int j=1;j<=now;++j){
					C(i+j,i+j,1,(LL)j);
				}
			}
			now=0;
			ans+=d[1].s;
		}
		else{
			R=ask(1,(LL)(now+1));
			if(i+now+1<=R) C(i+now+1,R,1,(LL)(now+1));
			ans+=d[1].s;
			ans+=(now+1)*(now+2)/(LL)2;
			++now;
		}
	}
	cout<<ans<<endl;
    return 0;
}