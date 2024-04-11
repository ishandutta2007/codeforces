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

const int N = 1e6 + 5,M = 8200;
int n,a[N],m = 8192,m2 = 5001;
int f[M][M];
vector<int> t[M];
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	fr(i,0,m2) {
		t[i].push_back(0);
		f[i][0] = 1;
	}
	fr(i,1,n) {
		cin >> a[i];
		for(auto x : t[a[i]]) {
			int res = x ^ a[i];
			fr(j,a[i]+1,m2) {
				if(f[j][res]) break;
				f[j][res] = 1;
				t[j].push_back(res);
			}
		}
		t[a[i]].clear();
	}
	int ans = 0;
	fr(i,0,m) if(f[m2][i]) ++ans;
	cout << ans << endl;
	fr(i,0,m) if(f[m2][i])
		cout << i << ' ';
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