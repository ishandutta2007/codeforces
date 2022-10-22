#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline ll qr(){
	ll in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
ll a[maxn],ans;
int n;
mt19937 rnd(time(0));
inline int genRnd(int l,int r){
	uniform_int_distribution<int>lim(l,r);
	return lim(rnd);
}
signed main(){
	n=qr();
	for(ri i=1;i<=n;++i)a[i]=qr();
	for(ri T=10;T;--T){
		vector<ll>fac;
		ri pos=genRnd(1,n);
		for(ri i=1,j=sqrt(a[pos]);i<=j;++i)
			if(a[pos]%i==0){
				fac.push_back(i);
				if(1ll*i*i!=a[pos])fac.push_back(a[pos]/i);
			}
		sort(fac.begin(),fac.end());
		vector<int>cnt(fac.size());
		for(ri i=1;i<=n;++i)++cnt[lower_bound(fac.begin(),fac.end(),__gcd(a[pos],a[i]))-fac.begin()];
		ri lim=lower_bound(fac.begin(),fac.end(),ans)-fac.begin();
		for(ri i=lim;i<fac.size();++i){
			for(ri j=i+1;j<fac.size();++j)
				if(fac[j]%fac[i]==0)
					cnt[i]+=cnt[j];
			if(cnt[i]<<1>=n)ans=fac[i];
		}
	}
	printf("%lld",ans);
	return 0;
}