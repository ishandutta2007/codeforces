#include<cstdio>
#include<set>
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

const int N=5e5+5;
int n,a[N],t,m=1e9;
struct Node {
	mutable ll l,r;
	bool operator < (const Node &o) const {
		return l<o.l;
	}
};
ll A,B;
set<Node> s;
int ans;
int Find(ll l,ll r) {
	l=A*l+B,r=A*r+B;
	if(l>r) swap(l,r);
	auto it=s.lower_bound((Node){l,l});
	if(it!=s.end()&&it->l<=r) return 1;
	if(it!=s.begin()&&(--it)->r>=l) return 1;
	return 0;
}
void Erase(ll l,ll r) {
	l=A*l+B,r=A*r+B;
	if(l>r) swap(l,r);
	auto it=s.lower_bound((Node){l,l});
	while(it!=s.end()&&it->l<=r) {
		if(it->r<=r) it=s.erase(it);
		else {
			it->l=r+1; break;
		}
	}
	if(it!=s.begin()&&(--it)->r>=l) it->r=l-1;
}
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		fr(i,1,n) scanf("%d",a+i);
		s.clear(); A=1,B=0;
		if(a[1]&1) ans=1,s.insert((Node){1,a[1]-1});
		else ans=0,s.insert((Node){a[1]/2,a[1]/2});
		fr(i,2,n) {
			Erase(a[i],m);
			if(!s.size()) {
				++ans; s.insert((Node){1,a[i]-1});
				A=1,B=0;
			}
			if(~a[i]&1) {
				if(Find(a[i]/2,a[i]/2)) s.clear();
				else ++ans;
				s.insert((Node){A*a[i]/2+B,A*a[i]/2+B});
			} else ++ans;
			B+=A*a[i],A*=-1;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}