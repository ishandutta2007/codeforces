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

const int N = 105;
int n,a[N];
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	int k;
	rf(i,n,1) {
		cout << "? ";
		fo(j,1,n) cout << i << ' ';
		cout << 1 << endl;
		cin >> k;
		if(k) {
			a[n] = i;
			break;
		}
	}
	if(!a[n]) a[n] = 1;
	fr(i,1,n) if(i != a[n]) {
		cout << "? ";
		fo(j,1,n) cout << a[n] << ' ';
		cout << i << endl;
		cin >> k;
		a[k] = i;
	}
	cout << "! ";
	fr(i,1,n) cout << a[i] << ' ';
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