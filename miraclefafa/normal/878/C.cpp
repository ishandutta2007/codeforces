#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=50100;
int n,k,a[20],l[N][20],r[N][20],sz[N];
set<PII> low[20],up[20];
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) {
		rep(j,0,k) scanf("%d",a+j);
		int pid=1e9+1,qid=-1;
		rep(j,0,k) {
			auto p=up[j].lower_bound(mp(a[j],0)); // 
			if (p!=up[j].end()) {
				pid=min(pid,l[p->se][0]);
			}
			auto q=low[j].upper_bound(mp(a[j],0));
			if (q!=low[j].begin()) {
				--q;
				qid=max(qid,l[q->se][0]);
			}
		}
		sz[i]=1;
		rep(j,0,k) l[i][j]=r[i][j]=a[j];
		if (pid<=qid) {
			while (1) {
				auto it=low[0].lower_bound(mp(pid,0));
				if (it==low[0].end()||it->fi>qid) break;
				int id=it->se;
				rep(j,0,k) {
					up[j].erase(mp(r[id][j],id));
					low[j].erase(mp(l[id][j],id));
					l[i][j]=min(l[i][j],l[id][j]);
					r[i][j]=max(r[i][j],r[id][j]);
				}
				sz[i]+=sz[id];
			}
		}
		rep(j,0,k) up[j].insert(mp(r[i][j],i)),low[j].insert(mp(l[i][j],i));
		printf("%d\n",sz[(--low[0].end())->se]);
	}
}