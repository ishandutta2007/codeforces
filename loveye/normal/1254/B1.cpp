#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e6 + 5;
int n,a[N],m = 1000000;
ll res,tmp;
int calc(int s,int k) {
	int ret = 0;
	if(res < k/2) {
		if(res + s < k/2) return res += s,-s + ret;
		ret -= k/2-res;
		s -= k/2-res;
		res = k/2;
	}
	if((k & 1) && s && res == k/2) --s,++res;
	if(res >= k/2) {
		if(res + s < k) return res += s,s + ret;
		ret += k-res;
		s -= k-res;
		res = 0;
	}
	if(res < k/2) {
		if(res + s < k/2) return res += s,-s + ret;
		ret -= k/2-res;
		s -= k/2-res;
		res = k/2;
	}
	if((k & 1) && s && res == k/2) --s,++res;
	if(res >= k/2) {
		if(res + s < k) return res += s,s + ret;
		ret += k-res;
		s -= k-res;
		res = 0;
	} return -2e9;
}
int main() {
	scanf("%d",&n);
	ll sum = 0;
	fr(i,1,n) {
		scanf("%d",a+i);
		sum += a[i];
	}
	if(sum == 1) return puts("-1"),0;
	ll ans = 9e18;
	fr(p,2,m) if(sum % p == 0) {
		do sum /= p; while(sum % p == 0);
		res = 0; tmp = 0;
		fr(i,1,n) tmp += 1ll * i * calc(a[i] % p,p);
		ans = min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}