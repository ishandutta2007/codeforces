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

const int N = 505;
int n,m,a[N],b[N];
int lcm(int a,int b) {return a / __gcd(a,b) * b;}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if(n == 1 && m == 1) cout << 0 << endl;
	else if(n == 1 || m == 1) {
		int cnt = 1;
		fr(i,1,n) {
			fr(j,1,m) cout << ++cnt << ' ';
			cout << endl;
		}
	} else {
		a[1] = 1,a[2] = 2;
		b[1] = 3,b[2] = 4;
		int cnt = 4;
		fr(i,3,n) a[i] = ++cnt;
		fr(i,3,m) b[i] = ++cnt;
		fr(i,1,n) {
			fr(j,1,m) cout << lcm(a[i],b[j]) << ' ';
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