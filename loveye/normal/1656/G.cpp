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

const int N=2e5+5;
int n,t,a[N],cnt[N],match[N],p[N],tot;
int out[N];
int f[N]; int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}
void merge(int x,int y) {
	x=getf(x),y=getf(y);
	if(x^y) f[x]=y;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t; while(t--) {
		cin>>n;
		fr(i,1,n) cnt[i]=0;
		fr(i,1,n) {
			cin>>a[i];
			cnt[a[i]]^=1;
		}
		if(n&1) {
			int res=0;
			fr(i,1,n) if(cnt[i]) ++res;
			if(res>1) cout<<"NO\n";
			else {
				fr(i,1,n) if(cnt[i]) res=i,cnt[i]=0;
				tot=0;
				fr(i,1,n) {
					if(a[i]==res&&i!=n+1>>1) p[i]=n+1>>1,match[i]=0,res=-1;
					else if(cnt[a[i]]) {
						match[match[cnt[a[i]]]=i]=cnt[a[i]];
						p[cnt[a[i]]]=++tot;
						p[i]=n-tot+1;
						cnt[a[i]]=0;
					} else cnt[a[i]]=i;
				}
				if(res!=-1) {
					cout<<"NO\n";
					continue;
				}
				iota(f+1,f+n+1,1);
				fr(i,1,n) merge(i,p[i]);
				fr(i,1,n) if(match[i]&&getf(i)!=getf(match[i])) {
					merge(i,match[i]);
					swap(p[i],p[match[i]]);
				}
				int rt=0;
				fr(i,1,n) if(match[i]) {
					if(!rt) {
						rt=getf(i);
						fr(j,1,n) if(getf(j)==rt) f[j]=i;
						rt=i;
					} else if(getf(i)^rt) {
						int u=rt,v=match[u],r=i,s=match[r];
						int pu=p[u],pv=p[v],pr=p[r],ps=p[s];
						p[u]=pr; p[v]=ps;
						p[r]=pv; p[s]=pu;
						merge(r,rt);
					}
				}
				cout<<"YES\n";
				fr(i,1,n) out[p[i]]=i;
				fr(i,1,n) cout<<out[i]<<' ';
				cout<<"\n";
			}
		} else {
			int ok=1;
			fr(i,1,n) if(cnt[i]) {ok=0; break;}
			if(!ok) cout<<"NO\n";
			else {
				tot=0;
				fr(i,1,n) {
					if(cnt[a[i]]) {
						match[match[cnt[a[i]]]=i]=cnt[a[i]];
						p[cnt[a[i]]]=++tot;
						p[i]=n-tot+1;
						cnt[a[i]]=0;
					} else cnt[a[i]]=i;
				}
				iota(f+1,f+n+1,1);
				fr(i,1,n) merge(i,p[i]);
				fr(i,1,n) if(getf(i)^getf(match[i])) {
					merge(i,match[i]);
					swap(p[i],p[match[i]]);
				}
				int rt=getf(1);
				fr(i,2,n) if(getf(i)^rt) {
					int u=rt,v=match[u],r=i,s=match[r];
					int pu=p[u],pv=p[v],pr=p[r],ps=p[s];
					p[u]=pr; p[v]=ps;
					p[r]=pv; p[s]=pu;
					merge(r,rt);
				}
				cout<<"YES\n";
				fr(i,1,n) out[p[i]]=i;
				fr(i,1,n) cout<<out[i]<<' ';
				cout<<"\n";
			}
		}
	}
	return 0;
}