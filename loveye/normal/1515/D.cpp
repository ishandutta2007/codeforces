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
int t,n,l,r,a[N],ans;
multiset<int> s;
multiset<int>::iterator it,it2;
int main() {
	cin >> t;
	while(t--) {
		ans = 0;
		cin >> n >> l >> r;
		fr(i,1,n) cin >> a[i];
		if(l > r) {
			swap(l,r);
			fr(i,1,l) swap(a[i],a[n+1-i]);
		}
		s.clear();
		fr(i,l+1,n) s.insert(a[i]);
		fr(i,1,l) {
			it = s.find(a[i]);
			if(it != s.end() && *it == a[i])
				s.erase(it);
			else ++ans;
		}
		int res1 = ans,res2 = (r-l) / 2;
		for(int i = 1;i <= n;++i) {
#define chk(it,i) (it != s.end() && *it == i)
			while(1) {
				it = s.find(i);
				if(!chk(it,i)) break;
				s.erase(it);
				it2 = s.find(i);
				if(!chk(it2,i)) {
					s.insert(i);
					break;
				} else {
					if(res2) --res2,++ans;
					else break;
					s.erase(it2);
				}
			}
		}
		cout << ans + res2 * 2 << endl;
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