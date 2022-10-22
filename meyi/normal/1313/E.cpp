#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
typedef unsigned long long ull;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int base=2333,maxn=15e5+10,mod1=1e9+7,mod2=1e9+9;
ll bs1[maxn],bs2[maxn];
inline void bs_init(int n){
	bs1[0]=bs2[0]=1;
	for(ri i=1;i<=n;++i){
		bs1[i]=bs1[i-1]*base%mod1;
		bs2[i]=bs2[i-1]*base%mod2;
	}
}
struct node{
	int n;
	char s[maxn];
	ll hsh1[maxn],hsh2[maxn];
	inline void init(){
		for(ri i=1;i<=n;++i){
			hsh1[i]=(hsh1[i-1]*base+s[i])%mod1;
			hsh2[i]=(hsh2[i-1]*base+s[i])%mod2;
		}
	}
	inline ull gethsh1(int l,int r){
		return (hsh1[r]-hsh1[l-1]*bs1[r-l+1]%mod1+mod1)%mod1;
	}
	inline ull gethsh2(int l,int r){
		return (hsh2[r]-hsh2[l-1]*bs2[r-l+1]%mod2+mod2)%mod2;
	}
	inline bool check(int l1,int r1,int l2,int r2){
		if(max(r1,r2)>n)return false;
		return gethsh1(l1,r1)==gethsh1(l2,r2)&&gethsh2(l1,r1)==gethsh2(l2,r2);
	}
	inline int lcp(int x,int y,int r){
		ri l=1,ret=0;
		while(l<=r){
			ri mid=l+r>>1;
			if(check(x,x+mid-1,y,y+mid-1))ret=mid,l=mid+1;
			else r=mid-1;
		}
		return ret;
	}
}a,b;
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(++k;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		T ret=0;
		for(++k;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>t1;
BIT<ll>t2;
int l[maxn],m,n,r[maxn],t_case;
char s[maxn];
ll ans;
signed main(){
	scanf("%d%d%s%s%s",&n,&m,a.s+1,b.s+1,s+1);
	bs_init(n+1+m);
	a.n=b.n=n;
	a.s[++a.n]='#';
	for(ri i=1;i<=m;++i)a.s[++a.n]=s[i];
	a.init();
	for(ri i=1;i<=n;++i)l[i]=min(a.lcp(i,n+2,n-i+1),m-1);
	reverse(b.s+1,b.s+n+1);
	b.s[++b.n]='#';
	for(ri i=m;i;--i)b.s[++b.n]=s[i];
	b.init();
	for(ri i=1;i<=n;++i)r[i]=min(b.lcp(n-i+1,n+2,i),m-1);
	t1.mx_idx=t2.mx_idx=m+1;
	for(ri i=1,j=1;i<=n;++i){
		while(j<=n&&j<=i+m-2){
			t1.add(m-r[j]-1,1);
			t2.add(m-r[j]-1,r[j]);
			++j;
		}
		ans+=1ll*t1.query(l[i])*(l[i]-m+1)+t2.query(l[i]);
//		printf("%d %lld\n",i,1ll*t1.query(l[i])*(l[i]-m+1)+t2.query(l[i]));
		t1.add(m-r[i]-1,-1);
		t2.add(m-r[i]-1,-r[i]);
	}
//	puts(a.s+1);
//	for(ri i=1;i<=n;++i)printf("%d ",l[i]);
//	printf("\n");
//	puts(b.s+1);
//	for(ri i=1;i<=n;++i)printf("%d ",r[i]);
//	printf("\n");
	printf("%lld",ans);
	return 0;
}