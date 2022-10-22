#include<cstdio>
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

const int N=1e5+5;
int n,a[N];
int _buc[N<<1],*buc=_buc+N;
int ans=N; vector<int> out,now;
void dfs(int u,int cnt,vector<int> v) {
	if(cnt>=ans) return;
	int mn=min(0,v[0]),mx=max(0,v.back());
	if(max(abs(mn),abs(mx))==1) {
		cnt+=!!mn+!!mx;
		if(cnt<ans) {
			ans=cnt;
			if(mn) now.push_back(-(1<<u));
			if(mx) now.push_back(1<<u);
			out=now;
			if(mn) now.pop_back();
			if(mx) now.pop_back();
		}
		return;
	}
	if(max(abs(mn),abs(mx))==0) return ans=cnt,out=now,void();
	int ok=1;
	fo(i,0,v.size()) if(v[i]&1) {
		ok=0; break;
	}
	if(ok) {
		fo(i,0,v.size()) v[i]>>=1;
		return dfs(u+1,cnt,v);
	}
	vector<int> vv(v.size());
	fo(i,0,v.size()) vv[i]=v[i]>>1;
	vv.erase(unique(vv.begin(),vv.end()),vv.end());
	now.push_back(1<<u);
	dfs(u+1,cnt+1,vv);
	now.pop_back();

	vv.resize(v.size());
	now.push_back(-(1<<u));
	fo(i,0,v.size()) vv[i]=v[i]+1>>1;
	vv.erase(unique(vv.begin(),vv.end()),vv.end());
	dfs(u+1,cnt+1,vv);
	now.pop_back();
}
int main() {
	cin>>n;
	fr(i,1,n) cin>>a[i];
	vector<int> tmp(a+1,a+n+1);
	sort(tmp.begin(),tmp.end());
	dfs(0,0,tmp);
	cout<<ans<<endl;
	for(auto x:out) cout<<x<<' ';
	cout<<endl;
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