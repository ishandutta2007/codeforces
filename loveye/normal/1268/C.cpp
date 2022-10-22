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

const int N = 2e5 + 5;
int n,p[N],q[N];
ll ans[N];
struct FWT {
	ll BIT[N];
	void add(int x,ll v) {for(;x <= n;x += x & -x) BIT[x] += v;}
	ll ask(int x) {ll z = 0; for(;x;x &= x-1) z += BIT[x]; return z;}
	int search(ll sum) {
		ll p = 0,z = 0;
		rf(k,18,0) if(p + (1 << k) < n && z + BIT[p + (1 << k)] < sum)
			z += BIT[p + (1 << k)],p += 1 << k;
		return p+1;
	}
} t1,t2;
ll gs(ll x) {return x * (x+1) / 2;}
int main() {
	cin.tie(0);
	cin >> n;
	fr(i,1,n) cin >> p[i],q[p[i]] = i;
	ll res = 0;
	fr(i,1,n) {
		t1.add(q[i],1);
		t2.add(q[i],q[i]);
		res += t1.ask(n) - t1.ask(q[i]);
		int k = t1.search(i + 1 >> 1);
		if(i & 1) {
			ans[i] = 1ll * (i>>1) * k - t2.ask(k-1) - gs(i>>1)
				+ (t2.ask(n) - t2.ask(k)) - 1ll * (i>>1) * k - gs(i>>1) + res;
		} else {
			ans[i] = 1ll * ((i>>1)-1) * k - t2.ask(k-1) - gs((i>>1)-1)
				+ (t2.ask(n) - t2.ask(k)) - 1ll * (i>>1) * k - gs(i>>1) + res;
		}
		cout << ans[i] << ' ';
	}
	cout << endl;
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