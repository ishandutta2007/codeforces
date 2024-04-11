#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=998244353;
ll powmod(ll a, ll k, ll mod=MOD){
    ll ap=a, ans=1;
    while(k){
        if(k&1){
            ans*=ap;
            ans%=mod;
        }
        ap=ap*ap;
        ap%=mod;
        k>>=1;
    }
    return ans;
}
ll inv(ll a){
    return powmod(a, MOD-2);
}
ll modsqrt(int p, int a){ //-1
	if(a==0) return 0;
	int q=p-1, s=0;
	while((q&1)==0){
		q>>=1;
		s++;
	}
	int z=2;
	while(1){
		if(powmod(z, (p-1)/2, p)==p-1) break;
		z++;
	}
	ll c=powmod(z, q, p);
	ll r=powmod(a, (q+1)/2, p), t=powmod(a, q, p);
	int m=s;
	while(t>1){
		ll tp=t;
		int k=-1;
		for(int i=1; i<m; i++){
			tp=tp*tp%p;
			if(tp==1){
				k=i; break;
			}
		}
		if(k==-1) return -1;
		ll cp=c;
		for(int i=0; i<m-k-1; i++) cp=cp*cp%p;
		c=cp*cp%p;
		t=c*t%p;
		r=cp*r%p;
		m=k;
	}
	return r;
}
const ll r=3;
struct NTT{
	ll zeta[24];
	NTT(){
		zeta[23]=powmod(r, (MOD-1)>>23);
		for(int i=22; i>=0; i--) zeta[i]=zeta[i+1]*zeta[i+1]%MOD;
	}
	vector<ll> fft(vector<ll> a, int k, bool inverse=false){
		int n=a.size();
		vector<ll> tmp(n);
		for(int t=1; t<=k; t++){
			ll w=1, z=zeta[t];
			if(inverse) z=inv(z);
			for(int i=0; i<n; i++){
				int l=i&((1<<(k-t))-1), h=i&~((1<<(k-t))-1);
				tmp[i]=(a[((h<<1)|l)&(n-1)]+w*a[((h<<1)|l|(1<<(k-t)))&(n-1)])%MOD;
				if((i&((1<<(k-t))-1))==(1<<(k-t))-1) (w*=z)%=MOD;
			}
			swap(a, tmp);
		}
		if(inverse){
			ll invn=inv(n);
			for(int i=0; i<n; i++) (a[i]*=invn)%=MOD;
		}
		return a;
	}
	vector<ll> multiply(vector<ll> a, vector<ll> b){
		int n=a.size()+b.size()-1, k=0;
		while((1<<k)<n) k++;
		n=(1<<k);
		a.resize(n), b.resize(n);
		a=fft(a, k), b=fft(b, k);
		vector<ll> c(n);
		for(int i=0; i<n; i++) c[i]=a[i]*b[i]%MOD;
		c=fft(c, k, true);
		return c;
	}
	vector<ll> inverse(vector<ll> a){
		ll a0=a[0], a0inv=inv(a0);
		int n=a.size();
		for(int i=0; i<n; i++) (a[i]*=a0inv)%=MOD;
		int k=0;
		while((1<<k)<n) k++;
		vector<ll> b(1, 1);
		for(int i=1; i<=k; i++){
			vector<ll> a1(1<<i);
			for(int j=0; j<min(1<<i, n); j++) a1[j]=a[j];
			vector<ll> b1=multiply(b, b);
			b1=multiply(b1, a1);
			b.resize(1<<i);
			for(int j=0; j<(1<<i); j++) b[j]=(2*b[j]-b1[j]+MOD)%MOD;
		}
		b.resize(n);
		for(int i=0; i<n; i++) (b[i]*=a0inv)%=MOD;
		return b;
	}
	vector<ll> log(vector<ll> a){
		int n=a.size();
		if(n==1){
			vector<ll> c(1);
			return c;
		}
		vector<ll> da(n);
		for(int i=0; i<n-1; i++) da[i]=a[i+1]*(i+1)%MOD;
		vector<ll> b=inverse(a);
		vector<ll> c=multiply(da, b);
		c.resize(n);
		vector<ll> invs(n);
		invs[1]=1;
		for(int i=2; i<n; i++) invs[i]=MOD-invs[MOD%i]*(MOD/i)%MOD;
		for(int i=n-1; i>=1; i--) c[i]=c[i-1]*invs[i]%MOD;
		c[0]=0;
		return c;
	}
	vector<ll> exp(vector<ll> a){
		int n=a.size();
		int k=0;
		while((1<<k)<n) k++;
		vector<ll> b(1, 1);
		for(int i=1; i<=k; i++){
			b.resize(1<<i);
			vector<ll> b1=log(b);
			for(int j=0; j<(1<<i); j++){
				b1[j]=MOD-b1[j];
				if(b1[j]>=MOD) b1[j]-=MOD;
			}
			for(int j=0; j<min(n, 1<<i); j++){
				b1[j]+=a[j];
				if(b1[j]>=MOD) b1[j]-=MOD;
			}
			b1[0]++;
			if(b1[0]>=MOD) b1[0]-=MOD;
			b=multiply(b, b1);
		}
		b.resize(n);
		return b;
	}
	vector<ll> sqrt(vector<ll> a){
		int n=a.size();
		int t=0;
		for(; t<n; t++){
			if(a[t]!=0) break;
		}
		if(t==n) return a;
		else if(t&1){
			vector<ll> ret(1, -1);
			return ret;
		}
		ll s=modsqrt(MOD, a[t]);
		if(s==-1){
			vector<ll> ret(1, -1);
			return ret;
		}
		ll a0inv=inv(a[t]);
		int n1=n-t, k=0;
		vector<ll> a1(n1);
		for(int i=0; i<n1; i++){
			a1[i]=a[i+t]*a0inv%MOD;
		}
		while((1<<k)<n1) k++;
		vector<ll> b(1, 1);
		for(int i=1; i<=k; i++){
			b.resize(1<<i);
			vector<ll> b1=inverse(b), a2(1<<i);
			for(int j=0; j<min(1<<i, n1); j++) a2[j]=a1[j];
			b1=multiply(b1, a2);
			for(int j=0; j<(1<<i); j++){
				b[j]=(b[j]+b1[j])*((MOD+1)>>1)%MOD;
			}
		}
		vector<ll> ret(n);
		for(int i=0; i<n1; i++) ret[i+(t>>1)]=b[i]*s%MOD;
		return ret;
	}
	vector<ll> div(vector<ll> a, vector<ll> b){
		if(a.size()<b.size()){
			vector<ll> ret(1);
			return ret;
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int n=a.size(), m=b.size();
		a.resize(n-m+1);
		b.resize(n-m+1);
		b=inverse(b);
		auto q=multiply(b, a);
		q.resize(n-m+1);
		reverse(q.begin(), q.end());
		return q;
	}
	vector<ll> mod(vector<ll> a, vector<ll> b){
		if(a.size()<b.size()) return a;
		auto c=multiply(b, div(a, b));
		for(int i=0; i<(int)b.size()-1; i++){
			a[i]+=MOD-c[i];
			if(a[i]>=MOD) a[i]-=MOD;
		}
		a.resize((int)b.size()-1);
		while(a.size()>1 && a.back()==0) a.pop_back();
		return a;
	}
	vector<ll> shift(vector<ll> a, ll c){//f(x+c)
		int n=a.size();
		vector<ll> f(n+1), invf(n+1);
		f[0]=1;
    	for(ll i=1; i<=n; i++) f[i]=f[i-1]*i%MOD;
    	invf[n]=inv(f[n]);
    	for(ll i=n-1; i>=0; i--) invf[i]=invf[i+1]*(i+1)%MOD;
		vector<ll> b(n);
		ll cp=1;
		for(int i=0; i<n; i++){
			b[i]=cp*invf[i]%MOD;
			(cp*=c)%=MOD;
		}
		for(int i=0; i<n; i++) (a[i]*=f[i])%=MOD;
		reverse(a.begin(), a.end());
		vector<ll> ret=multiply(a, b);
		ret.resize(n);
		reverse(ret.begin(), ret.end());
		for(int i=0; i<n; i++) (ret[i]*=invf[i])%=MOD;
		return ret;
	}
};
NTT ntt;
vector<ll> stirling_second(int n){
	if(n==0){
		vector<ll> ret(1, 1);
		return ret;
	}
	vector<ll> f(n+1), invf(n+1);
	f[0]=1;
	for(ll i=1; i<=n; i++) f[i]=f[i-1]*i%MOD;
    invf[n]=inv(f[n]);
	for(ll i=n-1; i>=0; i--) invf[i]=invf[i+1]*(i+1)%MOD;
	vector<ll> a(n+1), b(n+1);
	for(int i=1; i<=n; i++) a[i]=powmod(i, n)*invf[i]%MOD;
	for(int i=0; i<=n; i++){
		if(i&1) b[i]=MOD-invf[i];
		else b[i]=invf[i];
	}
	return ntt.multiply(a, b);
}
 
const int Maxn = 200005;
 
bool prime[Maxn];
int u[Maxn];
int n, k;
int sum;
int res;
 
int main()
{
	fill(prime + 2, prime + Maxn, true);
	fill(u, u + Maxn, 1);
	for (int i = 2; i < Maxn; i++) if (prime[i])
		for (int j = i; j < Maxn; j += i) {
			prime[j] = false;
			if (j / i % i == 0) u[j] = 0;
			else u[j] = -u[j];
		}
	scanf("%d %d", &n, &k);
	if (n == 1 || k == 1) { printf("1\n"); return 0; }
	int lst = -1;
	for (int i = 1; i < Maxn; i++) if (u[i]) {
		int len = (n - 1) / i + 1;
		if (len != lst) {
			lst = len;
			auto V = stirling_second(len);
			sum = 0;
			for (int i = 0; i <= k && i <= len; i++)
				sum = (sum + V[i]) % MOD;
		}
		if (u[i] > 0) res = (res + sum) % MOD;
		else res = (res - sum + MOD) % MOD;
	}
	res = (res + 4) % MOD;
	printf("%d\n", res);
	return 0;
}