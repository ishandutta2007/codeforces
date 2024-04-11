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

const int N = 4e5 + 5;
int n,t,vis[N],p[N];
vector<int> v;
int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		fr(i,1,n) cin >> p[i],vis[i] = 0;
		v.clear();
		fo(i,1,n) if(p[i] != p[i+1]) vis[i] = 1,v.push_back(i);
		int g = 0,s = 0,b = 0,id = -1;
		fr(i,1,n/2) if(vis[i]) id = i;
		if(id != -1) {
			fr(i,1,id/3) if(vis[i]) {
				int res = *lower_bound(v.begin(),v.end(),i*2+1);
				if(id-res > i) {
					g = i,s = res,b = id;
					break;
				}
			}
		}
		cout << g << ' ' << s-g << ' ' << b-s << endl;
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