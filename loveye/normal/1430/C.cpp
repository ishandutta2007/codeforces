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

const int N = 2e5 + 5;
int n,t,a[N];
vector<pair<int,int> > ans;
int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		cin >> n;
		fr(i,1,n) a[i] = i;
		rf(i,n,2) {
			ans.push_back(make_pair(a[i-1],a[i]));
			a[i-1] = a[i-1] + a[i] + 1 >> 1;
		}
		cout << a[1] << endl;
		fo(i,0,ans.size()) cout << ans[i].first << ' ' << ans[i].second << endl;
		ans.clear();
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