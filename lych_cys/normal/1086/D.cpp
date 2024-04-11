#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 200009
using namespace std;

int n,m,a[N],c[3][N],ch[209]; char s[N]; set<int> S[3];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void ins(int *c,int x,int y){
	for (; x<=n; x+=x&-x) c[x]+=y;
}
int qry(int *c,int x){
	int ans=0; for (; x; x^=x&-x) ans+=c[x]; return ans;
}
int getsum(int *c,int x,int y){
	if (x>y) return 0; 
	return qry(c,y)-qry(c,x-1);
}
void solve(){
	int i,ans=0;
	for (i=0; i<3; i++){
		int x=S[(i+1)%3].size();
		//cerr<<i<<' '<<x<<' '<<S[i].size()<<'\n';
		if (!x) ans+=S[i].size(); else{
			if (!S[(i+2)%3].size()) continue;
			int l=*(S[(i+1)%3].begin()),r=*(S[(i+1)%3].rbegin());
			int u=*(S[(i+2)%3].begin()),v=*(S[(i+2)%3].rbegin());
			//cerr<<l<<' '<<r<<' '<<u<<' '<<v<<'\n';
			ans+=getsum(c[i],u,v)+getsum(c[i],1,min(l,u))+getsum(c[i],max(r,v),n);
			//cerr<<ans<<'\n';
		}
	}
	printf("%d\n",ans);
}
int main(){
	ch['R']=0; ch['P']=1; ch['S']=2;
	scanf("%d%d%s",&n,&m,s+1);
	int i;
	for (i=1; i<=n; i++){
		a[i]=ch[s[i]];
		//cerr<<i<<' '<<a[i]<<'\n';
		ins(c[a[i]],i,1); S[a[i]].insert(i);
	}
	solve();
	while (m--){
		scanf("%d%s",&i,s);
		int x=ch[s[0]];
		S[a[i]].erase(i); ins(c[a[i]],i,-1);
		a[i]=x; S[x].insert(i);	ins(c[x],i,1);
		solve();
	}
	return 0;
}