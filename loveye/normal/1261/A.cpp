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

const int N = 2005;
int n,t,k,a[N];
char s[N];
vector<pair<int,int> > ans;
int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cin >> s+1;
		fr(i,1,n) a[i] = s[i] == ')';
		ans.clear();
		while(!is_sorted(a+1,a+n+1)) {
			int id = -1;
			fr(i,1,n) if(a[i] == 1) {
				id = i; break;
			}
			fr(i,id+1,n) if(a[i] == 0) {
				ans.emplace_back(id,i);
				reverse(a+id,a+i+1);
				break;
			}
		}
		fr(i,1,k-1) ans.emplace_back(2*i,n/2+i);
		cout << ans.size() << endl;
		for(auto p : ans) cout << p.first << ' ' << p.second << endl;
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