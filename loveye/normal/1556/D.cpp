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

const int N = 10005;
int n,k,a[N];
int b[N],c[N];
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	fr(i,2,n) {
		cout << "or " << 1 << ' ' << i << endl;
		cin >> b[i];
	}
	fr(i,2,n) {
		cout << "and " << 1 << ' ' << i << endl;
		cin >> c[i];
	}
	int t1,t2;
	cout << "or " << 2 << ' ' << 3 << endl;
	cin >> t1;
	cout << "and " << 2 << ' ' << 3 << endl;
	cin >> t2;
	a[1] = b[3] + c[3] + b[2] + c[2] - t1 - t2 >> 1;
	fr(i,2,n) a[i] = b[i] + c[i] - a[1];
	nth_element(a+1,a+k,a+n+1);
	cout << "finish " << a[k] << endl;
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