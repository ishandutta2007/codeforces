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
int n,t,nxt[N];
char s[N];
int len[N];
queue<int> q;
int main() {
	cin >> t;
	while(t--) {
		cin >> n >> s+1;
		nxt[n] = n+1;
		rf(i,n-1,1) if(s[i] != s[i+1]) nxt[i] = i+1;
		else nxt[i] = nxt[i+1];
		int last = 1,tot = 0,ans = 0;
		s[n+1] = '\0';
		fr(i,2,n+1) if(s[i] != s[i-1]) {
			len[++tot] = i-last;
			last = i;
			if(len[tot] > 1) q.push(tot);
		}
		fr(i,1,tot) if(!q.empty()) {
			++ans;
			if(len[i] > 1) q.pop();
			else if((--len[q.front()]) == 1) q.pop();
		} else {
			ans += (tot-i+2) >> 1; break;
		}
		cout << ans << endl;
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