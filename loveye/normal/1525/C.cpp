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

const int N = 3e5 + 5;
int n,a[N],a_[N],m,ans[N],id[N];
char s[N],s_[N];
vector<int> odd,even;
inline int cmp(const int &i,const int &j) {
	return a_[i] < a_[j];
}
int main() {
	ios::sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		fr(i,1,n) cin >> a_[i],id[i] = i;
		fr(i,1,n) cin >> s_[i];
		sort(id+1,id+n+1,cmp);
		fr(i,1,n) a[i] = a_[id[i]],s[i] = s_[id[i]];
		fr(i,1,n) ans[i] = -1;
		odd.clear(),even.clear();
		fr(i,1,n) if(a[i] & 1) {
			if(s[i] == 'L') {
				if(odd.size()) {
					int j = odd.back();
					ans[id[j]] = ans[id[i]] = (a[i] + (s[j] == 'L' ? a[j] : -a[j])) / 2;
					odd.pop_back();
				} else odd.push_back(i);
			} else odd.push_back(i);
		} else {
			if(s[i] == 'L') {
				if(even.size()) {
					int j = even.back();
					ans[id[j]] = ans[id[i]] = (a[i] + (s[j] == 'L' ? a[j] : -a[j])) / 2;
					even.pop_back();
				} else even.push_back(i);
			} else even.push_back(i);
		}
		while(odd.size() > 1) {
			int j = odd.back();
			odd.pop_back();
			int i = odd.back();
			odd.pop_back();
			if(s[i] == 'L') ans[id[i]] = ans[id[j]] = (a[i] + m + m-a[j]) / 2;
			else ans[id[i]] = ans[id[j]] = (m - a[j] + m - a[i]) / 2;
		}
		while(even.size() > 1) {
			int j = even.back();
			even.pop_back();
			int i = even.back();
			even.pop_back();
			if(s[i] == 'L') ans[id[i]] = ans[id[j]] = (a[i] + m + m-a[j]) / 2;
			else ans[id[i]] = ans[id[j]] = (m - a[j] + m - a[i]) / 2;
		}
		fr(i,1,n) cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}