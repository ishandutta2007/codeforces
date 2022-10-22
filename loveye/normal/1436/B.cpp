#include<bits/stdc++.h>
using namespace std;
const int MOD = 0;

const int S = 1 << 21;
char p0[S],*p1,*p2;
#ifndef ZXY
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
#endif
inline int read() {
	static int x,c;x = 0;
	do{c = getchar();}while(!isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();}while(isdigit(c));
	return x;
}

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &

const int N = 105;
int n,T,a[N][N];
inline int isprime(int x) {
	int sx = sqrt(x)+0.5;
	for(int i = 2;i <= sx;++i)
		if(x % i == 0) return 0;
	return 1;
}
int main() {
	cin >> T;
	while(T--) {
		cin >> n;
		memset(a,0,sizeof a);
		for(int d = 1;d <= n;++d)
			if(n % d == 0 && isprime(n/d)) {
				for(int i = 0;i < n;i += d)
					for(int j = 0;j < n;j += d)
						for(int p = 1;p <= d;++p)
							a[i+p][j+p] = 1;
				break;
			}
		for(int i = 1;i <= n;++i) {
			for(int j = 1;j <= n;++j)
				printf("%d ",a[i][j]);
			puts("");
		}
	}
	return 0;
}