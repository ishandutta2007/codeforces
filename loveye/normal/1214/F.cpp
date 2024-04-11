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
int n,m,a[N],b[N],ida[N],idb[N],match[N];
ll d[N<<1];
void add(int x,int v) {d[x+N]+=v;}
int main() {
	cin>>m>>n;
	fr(i,1,n) ida[i]=idb[i]=i;
	fr(i,1,n) cin>>a[i];
	fr(i,1,n) cin>>b[i];
	sort(ida+1,ida+n+1,[](const int &i,const int &j) {
		return a[i]<a[j];
	});
	sort(idb+1,idb+n+1,[](const int &i,const int &j) {
		return b[i]<b[j];
	});
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	fr(i,1,n) {
		int j=upper_bound(a+1,a+n+1,b[i])-a-1;
		add(1-i,b[i]); add(j-i+1,-b[i]); add(j+1-i,-b[i]); add(n-i+1,b[i]);
		//printf("%d %d %d\n",1-i,j-i,b[i]);
		//printf("%d %d %d\n",j-i+1,n-i,-b[i]);
	}
	fr(i,1,n) {
		int j=lower_bound(b+1,b+n+1,a[i])-b-1;
		add(i-n,-a[i]); add(i-j,a[i]); add(i-j,a[i]); add(i-1+1,-a[i]);
		//printf("%d %d %d\n",i-n,i-j-1,-a[i]);
		//printf("%d %d %d\n",i-j,i-1,a[i]);
	}
	fr(i,-n,n) d[i+N]+=d[i-1+N];
	//fr(i,-n,n) cout<<d[i+N]<<' '; cout<<endl;
	ll sa=0,sb=0;
	fr(i,1,n) {
		sa+=a[i];
		sb+=b[n+1-i];
		d[i+N]+=sa+1ll*i*m-sb;
	}
	sa=0,sb=0;
	fr(i,1,n) {
		sb+=b[i];
		sa+=a[n+1-i];
		d[N-i]+=sb+1ll*i*m-sa;
	}
	//fr(i,-n,n) cout<<d[i+N]<<' '; cout<<endl;
	int p=min_element(d+N-n,d+N+n+1)-d-N;
	printf("%lld\n",d[N+p]);
	if(p>=0) {
		fr(i,1,p) match[ida[i]]=idb[n+1-i];
		fr(i,p+1,n) match[ida[i]]=idb[i-p];
	} else {
		fr(i,1,n+p) match[ida[i]]=idb[i-p];
		fr(i,n+p+1,n) match[ida[i]]=idb[i-n-p];
	}
	fr(i,1,n) printf("%d ",match[i]);
	/*{ll ans=0;
	fr(i,1,n) ans+=abs(a[ida[i]]-b[idb[i]]);
	fr(i,1,n) {
		if(a[ida[i]]<b[idb[i]]) {
			p[++tot]=(Node){a[ida[i]],1};
			p[++tot]=(Node){b[idb[i]],-1};
		}
	}
	sort(p+1,p+tot+1,[](const Node &i,const Node &j) {
		return i.x<j.x;
	});
	int res=0;
	p[tot+1].x=m;
	fr(i,1,tot) {
		res+=p[i].v;
		cnt[res]+=p[i+1].x-p[i].x;
	}
	rf(i,n,1) cnt[i]+=cnt[i+1];
	fr(i,1,n) if(cnt[i]*2>m) ans+=m-cnt[i]*2;
	tot=0; memset(cnt,0,sizeof cnt);
	fr(i,1,n) {
		if(a[ida[i]]>b[idb[i]]) {
			p[++tot]=(Node){b[idb[i]],1};
			p[++tot]=(Node){a[ida[i]],-1};
		}
	}
	sort(p+1,p+tot+1,[](const Node &i,const Node &j) {
		return i.x<j.x;
	});
	res=0;
	p[tot+1].x=m;
	fr(i,1,tot) {
		res+=p[i].v;
		cnt[res]+=p[i+1].x-p[i].x;
	}
	rf(i,n,1) cnt[i]+=cnt[i+1];
	fr(i,1,n) if(cnt[i]*2>m) ans+=m-cnt[i]*2;
	printf("%lld\n",ans);}*/
	return 0;
}