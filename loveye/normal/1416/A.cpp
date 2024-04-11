#include<cstdio>
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
int t,n;
int a[N],ans[N];
vector<int> pos[N];
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		fr(i,1,n) pos[i].clear();
		fr(i,1,n) {
			cin>>a[i];
			pos[a[i]].push_back(i);
		}
		fr(i,1,n) ans[i]=n+1;
		fr(i,1,n) if(pos[i].size()) {
			int z=max(pos[i][0],n-pos[i].back()+1);
			fo(j,1,pos[i].size()) z=max(z,pos[i][j]-pos[i][j-1]);
			if(ans[z]==n+1) ans[z]=i;
		}
		fr(i,2,n) ans[i]=min(ans[i-1],ans[i]);
		fr(i,1,n) cout<<(ans[i]==n+1?-1:ans[i])<<' ';
		cout<<endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}