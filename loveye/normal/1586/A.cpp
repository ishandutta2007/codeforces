#include<cstdio>
#include<cmath>
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

const int N = 205;
int t,n,a[N];
int isprime(int x) {
	int sx = sqrt(x) + 0.5;
	fr(i,2,sx) if(x % i == 0) return 0;
	return 1;
}
int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		int s = 0;
		fr(i,1,n) cin >> a[i],s += a[i];
		if(isprime(s)) {
			cout << n-1 << endl;
			fr(i,1,n) if(a[i] & 1) {
				fr(j,1,n) if(j != i) cout << j << ' ' ;
				cout << endl;
				break;
			}
		} else {
			cout << n << endl;
			fr(i,1,n) cout << i << ' ' ;
			cout << endl;
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