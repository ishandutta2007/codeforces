#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define inf 1000000000
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define mpr make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define set_it set<int>:: iterator
#define l_bd lower_bound
#define u_bd upper_bound
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) x=(x+(y))%mod
#define N 100009
#define M 1000009
using namespace std;

int n,m,cnt,tp,q[N],sz[N],ta[N],e[M][3]; bool bo[N]; vi a[N],b[M];
set<int> S; set<int>:: iterator it;
void ins(int x,int y,int z){
	e[++cnt][0]=x; e[cnt][1]=y; e[cnt][2]=z;	
}
bool cmp(int x,int y){ return sz[x]<sz[y]; }
int main(){
	scanf("%d%d",&n,&m);
	int i,sum=0;
	for (i=1; i<=n; i++){
		int t; scanf("%d",&t); sz[i]=t; sum+=t;
		while (t--){ int x; scanf("%d",&x); a[i].pb(x); }
		if (a[i].size()!=sz[i]) while(1);
	}
	for (i=1; i<=n; i++) q[i]=i;
	sort(q+1,q+n+1,cmp);
	for (i=1; i<=n; i++) ta[q[i]]=sum/n+(n-i+1<=sum%n);
	for (i=1; i<=n; i++) if (sz[i]<ta[i]) S.insert(i);
	for (i=1; i<=n; i++)
		for (int p:a[i]) b[p].pb(i);
	for (i=1; i<=m; i++){
		for (int p:b[i]) bo[p]=1;
		it=S.begin();
		for (int p:b[i]){
			if (sz[p]>ta[p]){
				for (; it!=S.end(); it++){
					int x=*it;
					if (!bo[x] && sz[x]<ta[x]){
						ins(p,x,i); sz[p]--; sz[x]++;
						if (sz[x]==ta[x]) q[++tp]=x;
						it++; break;
					}
				}
			}
		}
		while (tp) S.erase(q[tp--]);
		for (int p:b[i]) bo[p]=0;
	}
	printf("%d\n",cnt);
	for (i=1; i<=cnt; i++) printf("%d %d %d\n",e[i][0],e[i][1],e[i][2]);
	return 0;
}