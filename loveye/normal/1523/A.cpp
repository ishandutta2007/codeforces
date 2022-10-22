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

const int N = 1050;
int n,m;
char s[N],last[N],a[N];
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m >> s+1;
		s[n+1] = last[n+1] = '\0';
		while(m--) {
			memcpy(last+1,s+1,sizeof(char) * n);
			fr(i,1,n) if((last[i-1] == '1') ^ (last[i+1] == '1'))
				s[i] = '1';
			if(strcmp(last+1,s+1) == 0) break;
		}
		cout << s+1 << endl;
	}
	return 0;
}