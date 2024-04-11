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

const int N = 505;
int n,a[N],id[N];
inline int cmp(const int &i,const int &j) {
	return a[i] < a[j];
}
struct Node {
	int u,v,w;
	inline bool operator < (const Node &o) const {
		return w < o.w;
	}
};
priority_queue<Node> pq;
string s;
inline int ask(int u,int v) {
	printf("? %d %d\n",u,v);
	fflush(stdout);
	cin >> s;
	return s[0] == 'Y';
}
int main() {
	cin >> n;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) fr(j,i+1,n) pq.push((Node){i,j,abs(a[i]-a[j])});
	int ok = 0;
	while(!pq.empty()) {
		Node now = pq.top(); pq.pop();
		int u = now.u,v = now.v;
		if(a[u] <= a[v]) {
			if(ask(v,u)) {
				printf("! %d %d\n",u,v);
				fflush(stdout);
				ok = 1;
				break;
			}
		}
		else if(ask(u,v)) {
			printf("! %d %d\n",u,v);
			fflush(stdout);
			ok = 1;
			break;
		}
	}
	if(!ok) {
		printf("! %d %d\n",0,0);
		fflush(stdout);
	}
	return 0;
}