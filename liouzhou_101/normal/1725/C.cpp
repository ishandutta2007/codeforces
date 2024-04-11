#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<set>
#define ll long long
#define maxn 300020
using namespace std;
ll a[maxn];
int n,m;
int sum;
#define mod 998244353
struct modint{
	int x;
	modint(int o=0){x=o;}
	modint &operator = (int o){return x=o,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
	modint &operator ^=(int b){
		modint a=*this,c=1;
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o){return *this *=o^=mod-2;}
	modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
	modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
	modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
	modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
	template<class I>friend modint operator +(modint a,I b){return a+=b;}
	template<class I>friend modint operator -(modint a,I b){return a-=b;}
	template<class I>friend modint operator *(modint a,I b){return a*=b;}
	template<class I>friend modint operator /(modint a,I b){return a/=b;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
}ans, aug, p[maxn], np[maxn], mp[maxn];
modint C(int n,int m){
	return p[n] * np[m] * np[n-m];
}
modint Solve(int n, int r,int c){
	modint c1 = c;
	c1 ^= (n-r);
	modint c2 = c-1;
	c2 ^= r;
	return c1 * c2;
}
int main(){

	p[0] = 1;
	for(int i=1;i<=300000;++i)p[i] = p[i-1] * i;
	np[300000] = 1;
	np[300000] /= p[300000];
	for(int i=300000;i>0;--i) np[i-1] = np[i] * i;
	ll all = 0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);
		all += a[i];
	}
	int sum = 0;
	int now = 0;
	ll nowr = 0;
	for(int i=0;i<n;++i){
		while(nowr * 2 < all){
			nowr += a[now];
			now = (now+1) % n;
		}
		if(nowr * 2 == all) ++ sum;
		nowr -= a[i];
	}
	sum /= 2;
//	printf("debug: %d\n", sum);
	for(int i=0;i<=sum;++i){
		if(i > m)break;
		aug = C(sum, i) * C(m, i) * p[i] * Solve(n-2*i, sum-i, m-i);
		ans += aug;
	}
	printf("%d\n", ans.x);
	return 0;
}