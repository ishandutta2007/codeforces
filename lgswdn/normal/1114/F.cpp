#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=4e5+9,mod=1e9+7;
typedef pair<int,int> pii;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,q,a[N],pr[N],inv[N],cnt;
bool vst[N];

int ksm(int a,int b) {
	if(b==0) return 1;
	else return ksm(a*a%mod,b/2)*(b%2==1?a:1)%mod;
}

void sieve() {
	rep(i,2,300) {
		if(vst[i]) continue;
		pr[++cnt]=i, inv[cnt]=ksm(i,mod-2);
		for(int j=2;i*j<=300;j++) vst[i*j]=1;
	}
}

struct node {int l,r,s,tg1,tg2,prod;} t[N*4];
void build(int p,int l,int r) {
	int mid=((t[p].l=l)+(t[p].r=r))/2;
	if(l==r) {
		rep(i,1,cnt) if(a[l]%pr[i]==0) t[p].s+=(1ll<<i);
		t[p].prod=a[l];
		t[p].tg1=0, t[p].tg2=1;
		return;
	}
	build(p*2,l,mid), build(p*2+1,mid+1,r);
	t[p].s=t[p*2].s|t[p*2+1].s, t[p].prod=t[p*2].prod*t[p*2+1].prod%mod;
	t[p].tg1=0, t[p].tg2=1;
}
void pushdown(int p) {
	t[p*2].s|=t[p].tg1, t[p*2+1].s|=t[p].tg1;
	t[p*2].tg1|=t[p].tg1, t[p*2+1].tg1|=t[p].tg1;
	int len=t[p*2].r-t[p*2].l+1;
	t[p*2].prod=(t[p*2].prod*ksm(t[p].tg2,len))%mod;
	t[p*2].tg2=(t[p*2].tg2*t[p].tg2)%mod;
	len=t[p*2+1].r-t[p*2+1].l+1;
	t[p*2+1].prod=(t[p*2+1].prod*ksm(t[p].tg2,len))%mod;
	t[p*2+1].tg2=(t[p*2+1].tg2*t[p].tg2)%mod;
	t[p].tg1=0, t[p].tg2=1;
}
void modify(int p,int x,int y,int g,int k) {
	int l=t[p].l, r=t[p].r, mid=(l+r)/2;
	if(l==x&&r==y) {
		t[p].s|=k, t[p].tg1|=k;
		t[p].prod=t[p].prod*ksm(g,r-l+1)%mod,
		t[p].tg2=t[p].tg2*g%mod;
		return;
	}
	pushdown(p);
	if(y<=mid) modify(p*2,x,y,g,k);
	else if(x>mid) modify(p*2+1,x,y,g,k);
	else modify(p*2,x,mid,g,k), modify(p*2+1,mid+1,y,g,k);
	t[p].s=t[p*2].s|t[p*2+1].s, t[p].prod=t[p*2].prod*t[p*2+1].prod%mod;
}
pii query(int p,int x,int y) {
	int l=t[p].l, r=t[p].r, mid=(l+r)/2;
	if(l==x&&r==y) return make_pair(t[p].s,t[p].prod);
	pushdown(p);
	if(y<=mid) return query(p*2,x,y);
	else if(x>mid) return query(p*2+1,x,y);
	else {
		pii a=query(p*2,x,mid), b=query(p*2+1,mid+1,y);
		return make_pair(a.first|b.first,a.second*b.second%mod);
	}
}

signed main() {
	n=read(), q=read();
	sieve();
	rep(i,1,n) a[i]=read();
	build(1,1,n);
	rep(i,1,q) {
		char opt[10]; scanf("%s",opt);
		if(opt[0]=='M') {
			int l=read(), r=read(), x=read(), s=0;
			rep(i,1,cnt) if(x%pr[i]==0) s+=(1ll<<i);
			modify(1,l,r,x,s);
		} else {
			int l=read(), r=read();
			pii res=query(1,l,r);
			int ans=res.second, s=res.first;
			rep(i,1,cnt) if(s&(1ll<<i)) ans=(ans*inv[i]%mod*(pr[i]-1)%mod);
			printf("%lld\n",ans);
		}
	} 
	return 0;
}