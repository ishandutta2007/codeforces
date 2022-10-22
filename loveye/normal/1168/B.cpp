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
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=3e5+5;
int n;
char s[N];
int mx;
void dfs(int cur) {
	fr(x,1,cur-1) fr(k,1,cur-1-x>>1)
		if(s[x]==s[x+k]&&s[x+k]==s[x+2*k]) return;
	mx=max(cur-1,mx);
	s[cur]='0';
	dfs(cur+1);
	s[cur]='1';
	dfs(cur+1);
}
int chk(int l,int r) {
	fr(x,l,r) fr(k,1,r-x>>1) if(s[x]==s[x+k]&&s[x]==s[x+2*k])
		return 1;
	return 0;
}
int main() {
	/*dfs(1);
	cout<<mx<<endl;
	return 0;*/
	scanf("%s",s+1);
	n=strlen(s+1);
	ll ans=0;
	fr(l,1,n) {
		int sx=min(n,l+7);
		fr(r,l,sx) ans+=chk(l,r);
		ans+=n-sx;
	}
	cout<<ans<<endl;
	return 0;
}