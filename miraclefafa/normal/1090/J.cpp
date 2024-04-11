#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int L=601000,N=101000;
char s[L];
int ss[L],sa[L],rk[L],bp[N],mg[N];
const ll mod1=1000000007;
const ll mod2=1000000009;
struct substr {
	int id,l,len;
};
typedef pair<int,int> hashv;
hashv base(13331,23333);
hashv hv[L],pw[L];

int n,m,u,v,_,len[10],p[N];

hashv operator + (hashv a,hashv b) {
	int c1=a.fi+b.fi,c2=a.se+b.se;
	if (c1>=mod1) c1-=mod1;
	if (c2>=mod2) c2-=mod2;
	return mp(c1,c2);
}

hashv operator - (hashv a,hashv b) {
	int c1=a.fi-b.fi,c2=a.se-b.se;
	if (c1<0) c1+=mod1;
	if (c2<0) c2+=mod2;
	return mp(c1,c2);
}

hashv operator * (hashv a,hashv b) {
	return mp(1ll*a.fi*b.fi%mod1,1ll*a.se*b.se%mod2);
}

void buildSA(int *s,int *sa,int *rk,int n,int m=128) {
	static int X[L],Y[L],c[L];
	int *x=X,*y=Y;
	rep(i,0,m) c[i]=0;
	rep(i,0,n) c[x[i]=s[i]]++;
	rep(i,1,m) c[i]+=c[i-1];
	per(i,0,n) sa[--c[x[i]]]=i;
	for (int k=1;k<n;k<<=1) {
		int p=0;
		per(i,n-k,n) y[p++]=i;
		rep(i,0,n) if (sa[i]>=k) y[p++]=sa[i]-k;
		rep(i,0,m) c[i]=0;
		rep(i,0,n) c[x[y[i]]]++;
		rep(i,1,m) c[i]+=c[i-1];
		per(i,0,n) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1; x[sa[0]]=0; y[n]=-1;
		rep(i,1,n) x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&
		y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		if (p==n) break;
		m=p;
	}
	rep(i,0,n)rk[sa[i]]=i;
	rep(i,0,n) hv[i+1]=hv[i]*base+mp(s[i],s[i]);
}

int pos(const substr &a) {
	return bp[a.id]+a.l;
}

hashv query(const substr &a) {
	int posl=bp[a.id]+a.l,posr=bp[a.id]+a.l+a.len;
	return hv[posr]-hv[posl]*pw[posr-posl];
}
int cmp(const substr& a,const substr& b) {
	int l=min(a.len,b.len);
	auto p1=query((substr){a.id,a.l,l}),p2=query((substr){b.id,b.l,l});
	if (p1==p2) {
		if (a.len<b.len) return -1;
		else if (a.len==b.len) return 0;
		else return 1;
	}
	return rk[pos(a)]<rk[pos(b)]?-1:1;
}

int lca(const substr& a,const substr& b) {
	int l=0;
	int r=min(a.len,b.len)+1;
	while (l+1<r) {
		int md=(l+r)>>1;
		auto p1=query((substr){a.id,a.l,md}),p2=query((substr){b.id,b.l,md});
		if (p1==p2) l=md; else r=md;
	}
	return l;
}


substr tmpa[20],tmpb[20];
int tmp[20];
int cmp(substr* a,int p1,substr* b,int p2) {
//	printf("faq\n");
	int q1=0,q2=0;
	while (q1<p1&&q2<p2) {
		if (a[q1].len==b[q2].len) {
			int r=cmp(a[q1],b[q2]);
			if (r==0) q1++,q2++;
			else return r;
		} else if (a[q1].len<b[q2].len) {
			substr c=b[q2];
			c.len=a[q1].len;
			int r=cmp(a[q1],c);
			if (r!=0) return r;
			else {
				b[q2].l+=a[q1].len;
				b[q2].len-=a[q1].len;
				q1++;
			}
		} else {
			substr c=a[q1];
			c.len=b[q2].len;
			int r=cmp(c,b[q2]);
			if (r!=0) return r;
			else {
				a[q1].l+=b[q2].len;
				a[q1].len-=b[q2].len;
				q2++;
			}			
		}
	}
	if (q1==p1&&q2==p2) return 0;
	if (q1==p1) return -1;
	else return 1;
}



int lca(substr* a,int p1,substr* b,int p2) {
//	printf("faq\n");
	int q1=0,q2=0;
	int len=0;
	while (q1<p1&&q2<p2) {
		if (a[q1].len==b[q2].len) {
			int r=cmp(a[q1],b[q2]);
			if (r==0) {
				len+=a[q1].len;
				q1++,q2++;
			} else {
				return len+lca(a[q1],b[q2]);
			}
		} else if (a[q1].len<b[q2].len) {
			substr c=b[q2];
			c.len=a[q1].len;
			int r=cmp(a[q1],c);
			if (r!=0) {
				return len+lca(a[q1],c);
			} else {
				len+=a[q1].len;
				b[q2].l+=a[q1].len;
				b[q2].len-=a[q1].len;
				q1++;
			}
		} else {
			substr c=a[q1];
			c.len=b[q2].len;
			int r=cmp(c,b[q2]);
			if (r!=0) {
				return len+lca(c,b[q2]);
			} else {
				len+=b[q2].len;
				a[q1].l+=b[q2].len;
				a[q1].len-=b[q2].len;
				q2++;
			}			
		}
	}
	return len;
}

int f[N],cl[N],minpr[N];
PII gap[N];
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
substr t1[10],t2[10];
void solve() {
	n=2;
	int cur=0;
	rep(i,0,n) {
		scanf("%s",s);
		bp[i]=cur;
		len[i]=strlen(s);
		rep(j,0,len[i]) ss[cur++]=s[j];
		ss[cur++]=129+i;
	}
	buildSA(ss,sa,rk,cur,130+n);
	rep(i,0,len[0]) p[i]=i+1;
	sort(p,p+len[0],[&](int a,int b) {
		t1[0]=(substr){0,0,a}; t1[1]=(substr){1,0,len[1]};
		t2[0]=(substr){0,0,b}; t2[1]=(substr){1,0,len[1]};
		return cmp(t1,2,t2,2)==-1;
	});
	rep(i,0,len[0]) {
		cl[i]=len[1]+p[i],f[i]=i;
		minpr[i]=p[i];
	}
	rep(i,1,len[0]) {
		t1[0]=(substr){0,0,p[i-1]}; t1[1]=(substr){1,0,len[1]};
		t2[0]=(substr){0,0,p[i]}; t2[1]=(substr){1,0,len[1]};
		gap[i]=mp(lca(t1,2,t2,2),i);
	}
	sort(gap+1,gap+len[0]);
	auto calc=[&](int cl,int minpr,int gap) {
		// [gap+1...cl]
		minpr=max(minpr,gap);
		return max(cl-minpr,0);
	};
	ll ans=0;
	per(i,1,len[0]) {
		int u=find(gap[i].se);
		int v=find(gap[i].se-1);
		ans+=calc(cl[u],minpr[u],gap[i].fi);
		ans+=calc(cl[v],minpr[v],gap[i].fi);
		f[v]=u;
		minpr[u]=min(minpr[u],minpr[v]);
		cl[u]=gap[i].fi;
	}
	ans+=calc(cl[find(0)],minpr[find(0)],0);
	printf("%lld\n",ans);
}
int main() {
	pw[0]=mp(1,1);
	rep(i,1,600001) pw[i]=pw[i-1]*base;
	solve();
}