#include<cstdio>
#include<set>
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
int n,m;
set<int> s;
int seg[N<<2];
void change(int k,int l,int r,int p,int v) {
	if(l==r) return seg[k]=min(seg[k],v),void();
	int mid=l+r>>1;
	if(p<=mid) change(k<<1,l,mid,p,v);
	else change(k<<1|1,mid+1,r,p,v);
	seg[k]=min(seg[k<<1],seg[k<<1|1]);
}
int query(int k,int l,int r,int x,int y) {
	if(x<=l&&r<=y) return seg[k];
	int mid=l+r>>1,z=n+1;
	if(x<=mid) z=query(k<<1,l,mid,x,y);
	if(y>mid) z=min(query(k<<1|1,mid+1,r,x,y),z);
	return z;
}
int main() {
	memset(seg,0x3f,sizeof seg);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	fr(i,1,n) s.insert(i);
	fr(i,1,n) change(1,1,n,i,n+1);
	fr(i,1,m) {
		static int op,l,r,x;
		cin>>op;
		if(op==0) {
			cin>>l>>r>>x;
			if(x==0) {
				while(1) {
					auto it=s.lower_bound(l);
					if(it!=s.end()&&*it<=r)
						s.erase(it);
					else break;
				}
			} else change(1,1,n,l,r);
		}
		else {
			int mask=0;
			cin>>x;
			auto it=s.lower_bound(x);
			if(it!=s.end()&&*it==x) {
				mask|=2;
				l=it!=s.begin()?*prev(it)+1:1;
				r=(++it)!=s.end()?*it:n+1;
				if(query(1,1,n,l,x)>=r) mask|=1;
			} else mask=1;
			cout<<(mask==3?"N/A":(mask==2?"YES":"NO"))<<'\n';
		}
	}
	return 0;
}