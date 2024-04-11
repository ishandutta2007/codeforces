#include<cstdio>
#include<queue>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5;
int n;
char s[N];
queue<int> q[2];
int cnt;
vector<int> ans[N];
int main() {
	cin>>s+1;
	n=strlen(s+1);
	fr(i,1,n) if(s[i]=='0') {
		int u;
		if(q[0].size()) u=q[0].front(),q[0].pop();
		else u=++cnt;
		ans[u].push_back(i);
		q[1].push(u);
	} else {
		int u;
		if(q[1].size()) u=q[1].front(),q[1].pop();
		else return puts("-1"),0;
		ans[u].push_back(i);
		q[0].push(u);
	}
	if(!q[0].size()) {
		printf("%d\n",cnt);
		fr(i,1,cnt) {
			printf("%d ",int(ans[i].size()));
			for(auto x:ans[i]) printf("%d ",x);
			puts("");
		}
	} else puts("-1");
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}