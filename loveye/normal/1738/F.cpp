#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=1005;
int n,d[N],id[N];
bool vis[N];
int f[N]; int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}
void merge(int x,int y) {
	x=getf(x),y=getf(y);
	if(x^y) f[x]=y;
}
int main() {
	ios::sync_with_stdio(0);
	int T; cin>>T;
	while(T--) {
		cin>>n;
		fr(i,1,n) cin>>d[i],id[i]=i;
		sort(id+1,id+n+1,[](const int &i,const int &j) {
			return d[i]>d[j];
		});
		fr(i,1,n) vis[i]=0;
		fr(i,1,n) f[i]=i;
		fr(i,1,n) if(!vis[id[i]]) {
			int u=id[i];
			vis[u]=1;
			fr(j,1,d[u]) {
				int v;
				cout<<"? "<<u<<endl;
				cin>>v; merge(u,v);
				if(vis[v]) break;
				vis[v]=1;
			}
		}
		cout<<"! ";
		fr(i,1,n) cout<<getf(i)<<' ';
		cout<<endl;
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}