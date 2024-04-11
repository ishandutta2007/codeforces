#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000009;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
map<PII,int> hs;
set<int> st;
int n,x[N],y[N];
ll ans;
bool exist(int x,int y) { return hs.count(mp(x,y))&&hs[mp(x,y)]!=-1;}
bool check(int x,int y) {
	if (!exist(x,y)) return 1;
	if (y==0) return 1;
	if (!exist(x-1,y-1)&&!exist(x,y-1)&&!exist(x+1,y-1)) return 0;
	return 1;
}
bool valid(int p) {
	int cx=x[p],cy=y[p];
	hs[mp(cx,cy)]=-1;
	if (!check(cx-1,cy+1)||!check(cx,cy+1)||!check(cx+1,cy+1)) {
		hs[mp(cx,cy)]=p;
		return 0;
	}
	hs[mp(cx,cy)]=p;
	return 1;
}
void refresh(int x,int y) {
	if (!exist(x,y)) return;
	int p=hs[mp(x,y)];
	if (st.count(p)) st.erase(p);
	if (valid(p)) st.insert(p);
}
void del(int p) {
//	printf("%d\n",p);
	ans=(ans*n+p)%mod;
	hs[mp(x[p],y[p])]=-1; st.erase(p);
	refresh(x[p]-2,y[p]);
	refresh(x[p]-1,y[p]);
	refresh(x[p]+1,y[p]);
	refresh(x[p]+2,y[p]);
	refresh(x[p]-1,y[p]-1);
	refresh(x[p],y[p]-1);
	refresh(x[p]+1,y[p]-1);
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d",x+i,y+i),hs[mp(x[i],y[i])]=i;
	rep(i,0,n) if (valid(i)) st.insert(i);
	rep(i,0,n) {
		assert(!st.empty());
		if (i%2==0) del(*(--st.end()));
		else del(*st.begin());
	}
	printf("%I64d\n",ans);
}