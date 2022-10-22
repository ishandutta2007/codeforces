#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
typedef vector<int> Poly;
const int MAXN=3e5+5,mod=998244353,G=3,invG=(mod+1)/3;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll fac[MAXN],inv[MAXN];
ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int n,f[MAXN],g[MAXN];
Poly a;
void Butterfly(Poly &a){
	static const int g = G;
    int n(a.size()), h(__builtin_ctz(n));

    static bool first = true;
    static int sum_e[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
    if (first) {
        first = false;
        int es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = __builtin_ctz(mod - 1);
        ll e = Fstpw(g, mod - 1 >> cnt2), ie = Fstpw(e, mod - 2);
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
			e = e * e % mod;
			ie = ie * ie % mod;
        }
        ll nw = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e[i] = es[i] * nw % mod;
			nw = nw * ies[i] % mod;
        }
    }
    for (int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        ll nw = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                int l = a[i + offset];
                int r = a[i + offset + p] * nw % mod;
                a[i + offset] = (l + r) % mod;
                a[i + offset + p] = (mod + l - r) % mod;
            }
            nw = nw * sum_e[__builtin_ctz(~(unsigned int)(s))] % mod;
        }
    }
	return ;
}
void Butterfly_inv(Poly &a) {
    static const int g = G;
    int n(a.size()), h(__builtin_ctz(n));

    static bool first = true;
    static int sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
    if (first) {
        first = false;
        int es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = __builtin_ctz(mod - 1);
        ll e = Fstpw(g, mod - 1 >> cnt2), ie = Fstpw(e, mod - 2);
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
			e = e * e % mod;
			ie = ie * ie % mod;
        }
        ll nw = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * nw % mod;
			nw = nw * es[i] % mod;
        }
    }

    for (int ph = h; ph; ph--) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        ll inw = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                int l = a[i + offset];
                int r = a[i + offset + p];
                a[i + offset] = (l + r) % mod;
                a[i + offset + p] = (mod + l - r) % mod * inw % mod;
            }
            inw = inw * sum_ie[__builtin_ctz(~(unsigned int)(s))] % mod;
        }
    }
	return ;
}
Poly operator *(Poly a,Poly b){
	if(a.empty() || b.empty()) return Poly{};
    int n(a.size() - 1), m(b.size() - 1);
    if (min(n, m) <= 30) {
        if (n < m) {
            swap(n, m);
            swap(a, b);
        }
        Poly ans(n + m + 1);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                ans[i + j] = (ans[i + j] + 1ll * a[i] * b[j]) % mod;
        return ans;
    }
    int z = 1;
	while(z <= n + m) z <<= 1;
    a.resize(z);
    Butterfly(a);
    b.resize(z);
    Butterfly(b);
    for (int i = 0; i < z; i++) 
        a[i] = 1ll * a[i] * b[i] % mod;
    Butterfly_inv(a);
    a.resize(n + m + 1);
    ll iz = Fstpw(z, mod - 2);
    for (int i = 0; i <= n + m; i++)
		a[i] = a[i] * iz % mod;
    return a;
}
int ans;
void Fuck(){
	n=4;
	int p[10],q[10];
	for(int i=1; i<=n; i++)
		p[i]=i;
	int res=0;
	do{
		for(int i=1; i<=n; i++)
			q[p[i]]=i;
		int ok=1;
		for(int i=1; i<=n; i++)
			if(abs(p[i]-q[i])>1) ok=0;
		res+=ok;
	}while(next_permutation(p+1,p+n+1));
	printf("%d\n",res);
	return ;
}
int main(){
	//Fuck(); return 0;
	//freopen("in1.txt","r",stdin);
	n=3e5;
	//n=100;
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	for(int i=0; i<=n; i++)
		f[i]=inv[i];
	for(int i=0,j=1; i<=n; i+=2,j=j*(mod+1ll)/2%mod)
		g[i]=j*inv[i/2]%mod;
	a=(Poly(f,f+n+1))*(Poly(g,g+n+1));
	for(int i=0; i<=n; i++)
		a[i]=a[i]*fac[i]%mod;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=0;
		for(int k=0,j=1; k*4<=n; k++,j=j*(mod+1ll)/1%mod)
			ans=(ans+C(n-k*2,k*2)*a[n-k*4]%mod*j%mod*fac[k*2]%mod*inv[k])%mod;
		printf("%d\n",ans);
	}
	return 0;
}