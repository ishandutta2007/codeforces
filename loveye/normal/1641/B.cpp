#include<cstdio>
#include<map>
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

const int N=505;
int t;
int a[N],n,vis[N];
map<int,int> cnt;
vector<pair<int,int> > out;
vector<int> ans;
int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--) {
		out.clear();
		ans.clear();
		cnt.clear();
		cin>>n;
		fr(i,1,n) cin>>a[i];
		fr(i,1,n) ++cnt[a[i]];
		int ok=1;
		for(auto x:cnt) if(x.second&1) {
			ok=0; break;
		}
		if(!ok) {
			cout<<-1<<endl;
			continue;
		}
		fr(i,1,n) vis[i]=0;
		rf(i,n,1) if(!vis[i]) {
			rf(j,i-1,1) if(!vis[j]&&a[i]==a[j]) {
				vis[i]=vis[j]=1;
				int st=0,pt=0;
				fr(k,1,j) if(!vis[k]) ++st;
				rf(k,i-1,j+1) if(!vis[k]) out.push_back(make_pair(st+(pt++),a[k]));
				reverse(a+j+1,a+i-1+1);
				reverse(vis+j+1,vis+i-1+1);
				ans.push_back(pt+1);
				break;
			}
		}
		reverse(ans.begin(),ans.end());
		cout<<out.size()<<endl;
		for(auto x:out) cout<<x.first<<' '<<x.second<<endl;
		cout<<ans.size()<<endl;
		for(auto x:ans) cout<<x*2<<' ';
		cout<<endl;
	}
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