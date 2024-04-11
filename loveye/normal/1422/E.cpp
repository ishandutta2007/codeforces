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

const int N = 1e5 + 5;
int n,nxt[N],nxtc[N];
bool ok[N];
char s[N];
struct Answer {int len; char s[10];} ans[N];
deque<int> now;
int main() {
	cin >> s+1;
	n = strlen(s+1);
	rf(i,n,1) {
		if(s[i] == s[i+1]) nxt[i] = nxt[i+1],ok[i] = ok[i+1];
		else nxt[i] = i+1,ok[i] = (!now.empty() && (s[i] < s[now[0]] || (s[i] == s[now[0]] && ok[now[0]])));
		if(ok[i]) now.push_front(i);
		else {
			if(nxt[i]-i & 1) now.push_front(i);
			else now.pop_front();
		}
		ans[i].len = now.size();
		if(now.size() > 10) {
			fo(j,0,5) ans[i].s[j] = s[now[j]];
			fo(j,5,8) ans[i].s[j] = '.';
			ans[i].s[8] = s[now[now.size()-2]];
			ans[i].s[9] = s[now[now.size()-1]];
		} else fo(j,0,now.size()) ans[i].s[j] = s[now[j]];
	}
	fr(i,1,n) cout << ans[i].len << ' ' << ans[i].s << endl;
	return 0;
}