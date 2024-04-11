#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 105,M = 2000 * N;
int n,a[N];
bitset<M> dp;
int main() {
	cin >> n;
	int sum = 0;
	fr(i,1,n) cin >> a[i],sum += a[i];
	while(1) {
		int ok = 1;
		fr(i,1,n) if(a[i] & 1) {ok = 0; break;}
		if(ok && sum % 2 == 0) {
			fr(i,1,n) a[i] /= 2;
			sum >>= 1;
		} else break;
	}
	dp[0] = 1;
	fr(i,1,n) dp |= dp << a[i];
	if((sum & 1) || dp[sum/2] == 0) cout << 0 << endl;
	else {
		fr(i,1,n) if(a[i] & 1) {
			cout << 1 << endl << i << endl;
			break;
		}
	}
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