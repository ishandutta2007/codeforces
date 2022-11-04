#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+9, M=29, mod=998244353;

int n,m,l[N],r[N],u[N],v[N];

int fac[N],inv[N],ifac[N];
void pre() {
	inv[0]=inv[1]=fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=n;i++) ifac[i]=ifac[i-1]*inv[i]%mod;
}
int C(int x,int y) {
	if(x<0||y<0||x<y) return 0;
	else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

int cf[N],p[N],s[N][49];
void cal_p() {
	for(int i=1;i<=n;i++) cf[l[i]]++, cf[r[i]+1]--;
	int ssum=0;
	for(int i=1;i<=n;i++) ssum+=cf[i], p[i]=ssum;
	for(int j=0;j<=2*m;j++) for(int i=1;i<=n;i++) {
		s[i][j]=(s[i-1][j]+C(p[i]-j,i-j))%mod;
	}
}

struct hset {
	bool vst[N];
	int ar[N], size;
	void clear() {
		for(int i=1;i<=size;i++) vst[ar[i]]=0;
		size=0;
	}
	void add(int x) {if(!vst[x]) ar[++size]=x, vst[x]=1;}
}st;

#define bit(S,i) (bool)((1<<i-1)&S)
int ans;
void in_ex() {
	for(int S=0;S<(1<<m);S++) {
		int L=1, R=n, pop=0;
		for(int j=1;j<=m;j++) if(bit(S,j)) {
			L=max(L,l[u[j]]), R=min(R,r[u[j]]), st.add(u[j]);
			L=max(L,l[v[j]]), R=min(R,r[v[j]]), st.add(v[j]);
			pop++;
		}
		if(L>R) {st.clear();continue;}
		int res=(s[R][st.size]-s[L-1][st.size]+mod)%mod;
		ans=(ans+res*(pop&1 ? -1 : 1)+mod)%mod;
		st.clear();
	}
}

signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&l[i],&r[i]);
	for(int i=1;i<=m;i++) scanf("%lld%lld",&u[i],&v[i]);
	pre();
	cal_p();
	in_ex();
	printf("%lld",(ans+mod)%mod);
	return 0;
}