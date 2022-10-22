#include<cstdio>
#include<queue>
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
int n,m;
deque<int> a;
struct Query {ll t,id;} q[N*3];
int ans1[N*3],ans2[N*3];
int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	a.resize(n);
	fo(i,0,n) cin>>a[i];
	int id=0;
	fo(i,1,n) if(a[i]>a[id]) id=i;
	fr(i,1,m) cin>>q[i].t,q[i].id=i;
	sort(q+1,q+m+1,[](const Query &a,const Query &b) {
		return a.t<b.t;
	});
	int cur=0,A,B;
	fr(i,1,m) {
		for(;cur<id&&cur<q[i].t;++cur) {
			A=a[0],B=a[1];
			a.pop_front();
			a.pop_front();
			if(A>B) {
				a.push_front(A);
				a.push_back(B);
			} else {
				a.push_front(B);
				a.push_back(A);
			}
		}
		if(cur==q[i].t) ans1[q[i].id]=A,ans2[q[i].id]=B;
		else ans1[q[i].id]=a[0],ans2[q[i].id]=a[1+(q[i].t-cur-1)%(n-1)];
	}
	fr(i,1,m) printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}