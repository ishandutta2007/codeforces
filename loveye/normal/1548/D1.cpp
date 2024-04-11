#include<bits/stdc++.h>
using namespace std;

int read();
#define ll long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 6005;
int n;
int x[N],y[N];
int gcd(int x,int y) {
	return !y ? x : gcd(y,x % y);
}
int cnt[2][2];
int main() {
	scanf("%d",&n);
	fr(i,1,n) {
		scanf("%d%d",x+i,y+i);
		x[i] = x[i] >> 1 & 1;
		y[i] = y[i] >> 1 & 1;
	}
	ll ans = 0;
	fr(i,1,n) {
		fr(j,i+1,n) {
			fr(a,0,1) fr(b,0,1) {
				int A = (a ^ x[i]) | (b ^ y[i]);
				int B = (a ^ x[j]) | (b ^ y[j]);
				int C = (x[j] ^ x[i]) | (y[j] ^ y[i]);
				if((A ^ B ^ C) == 0) ans += cnt[a][b];
			}
		}
		++cnt[x[i]][y[i]];
	}
	printf("%lld\n",ans);
	return 0;
}