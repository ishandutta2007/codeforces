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
int n,a[N],k;
char s[N];
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	fr(i,1,n) cin >> a[i];
	sort(a+1,a+n+1);
	cin >> s+1;
	fr(i,2,n) if(s[i] != s[i-1]) ++k;
	int l = n-k,r = n-k;
	cout << a[l--] << ' ' << s[1] << endl;
	int fl1 = (s[1] == 'L'),fl2 = (s[1] == 'L');
	fr(i,2,n) if(s[i] == s[i-1]) cout << a[l--] << ' ' << ((fl1 ^= 1) ? 'L' : 'R') << endl;
	else cout << a[++r] << ' ' << ((fl2 ^= 1) ? 'L' : 'R') << endl;
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