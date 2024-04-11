#include<cstdio>
#include<map>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=(2e5+5)*4;
int n,s,a[N],b[N];
map<int,vector<int> > mp;
int nds;
int fir[N],to[N],eds,nxt[N],vis[N];
void addedge(int u,int v) {
	//cout << u << ' ' << v << endl;
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
int out[N],stk[N],top,ans[N];
void Euler(int u) {
	for(int &i=fir[u],v;v=to[i],i;i=nxt[i]) {
		if(vis[i]) continue;
		vis[i]=1;
		Euler(v);
		if(u<=n) out[u]=stk[top-1];
	}
	stk[++top]=u;
}
vector<vector<int> > out1;
vector<int> out2;
int main() {
	scanf("%d%d",&n,&s);
	fr(i,1,n) {
		scanf("%d",a+i),b[i]=a[i];
		mp[a[i]].push_back(i);
	}
	sort(b+1,b+n+1);
	int lst=1,cnt=0;
	nds=n;
	fr(i,1,n) if(i==n||b[i]!=b[i+1]) {
		vector<int> &now=mp[b[i]];
		auto st=lower_bound(now.begin(),now.end(),lst);
		auto ed=upper_bound(now.begin(),now.end(),i);
		for(;st!=ed;++st) ans[*st]=*st,++cnt;
		++nds;
		for(auto x:now) if(!ans[x]) addedge(x,nds);
		fr(j,lst,i) if(!ans[j]) addedge(nds,j);
		lst=i+1;
	}
	if(n-cnt>s) return puts("-1"),0;
	fr(i,1,n) if(!ans[i]&&!out[i]) Euler(i);
	memset(vis,0,sizeof vis);
	fr(i,1,n) if(out[i]&&!vis[i]) {
		int u=i; out2.push_back(u);
		out1.resize(out1.size()+1);
		do out1.back().push_back(u),vis[u]=1,u=out[u];
		while(!vis[u]);
	}
	int rest=min(s-(n-cnt)-1,int(out1.size()-1));
	if(rest>1) {
		printf("%d\n",int(out1.size())-rest+1);
		int _=0;
		fr(i,0,rest) _+=out1[i].size();
		printf("%d\n",_);
		fr(i,0,rest) for(auto x:out1[i]) printf("%d ",x);
		puts("");
		printf("%d\n",rest+1);
		rf(i,rest,0) printf("%d ",out2[i]);
		puts("");
		fo(i,rest+1,out1.size()) {
			printf("%d\n",int(out1[i].size()));
			for(auto x:out1[i]) printf("%d ",x);
			puts("");
		}
	} else {
		printf("%d\n",int(out1.size()));
		fo(i,0,out1.size()) {
			printf("%d\n",int(out1[i].size()));
			for(auto x:out1[i]) printf("%d ",x);
			puts("");
		}
	}
	return 0;
}