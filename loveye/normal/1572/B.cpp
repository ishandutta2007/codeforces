#include<cstdio>
#include<cassert>
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
int n,a[N];
vector<int> ans,t;
void Erase(int l,int r) {
	if(l > r) return;
	assert((r-l+1) % 2 == 0);
	if(r < n && a[r+1] == 0) {
		for(int i = r-1;i >= l;i -= 2)
			ans.push_back(i),a[i] = a[i+1] = 0;
	} else if(l > 1 && a[l-1] == 0) {
		for(int i = l;i <= r;i += 2)
			ans.push_back(i-1),a[i] = a[i+1] = 0;
	} else assert(0);
}
int main() {
	int T; cin >> T;
	while(T--) {
		cin >> n;
		int sum = 0;
		fr(i,1,n) cin >> a[i],sum ^= a[i];
		if(sum & 1) cout << "NO" << endl;
		else {
			int lst = 0;
			t.clear();
			fr(i,1,n)
				if(i == n || a[i] != a[i+1])
					t.push_back(i-lst),lst = i;
			int s = a[1],cnt = 0;
			fo(i,0,t.size()) {
				if(s && (t[i] & 1)) ++cnt;
				s ^= 1;
			}
			if(t.size() == 1) {
				if(a[1]) cout << "NO" << endl;
				else cout << "YES\n0" << endl;
				continue;
			}
			int l = 1,r = 1;
			while(r <= n) {
				if(a[r] == 1) ++r;
				else if(l == r) ++l,++r;
				else {
					if(r == n) break;
					if((r-l+1) % 2 == 1) Erase(l,r-1),l = r = r+1;
					else {
						ans.push_back(r-1);
						a[r-1] = a[r] = a[r+1] = a[r-1] ^ a[r] ^ a[r+1];
						if(a[r]) r += 2;
						else Erase(l,r-2),l = r = r+2;
					}
				}
			}
			if((r-l+1) % 2 == 0 || (l == 1 && r == n+1)) cout << "NO" << endl;
			else {
				if(l <= r) Erase(l,r-1);
				assert(ans.size() <= n);
				cout << "YES" << endl;
				cout << ans.size() << endl;
				for(auto x : ans) cout << x << ' ';
				cout << endl;
			}
			ans.clear();
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