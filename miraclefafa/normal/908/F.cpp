#include <bits/stdc++.h>
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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
VI v[3];
int n,col[N];
ll x[N],ret;
char p[30];
ll gao(ll preG,ll curG) {
	ll ret=0;
	if (preG==-1) {
		if (!v[1].empty()) ret+=curG-v[1].front();
		if (!v[2].empty()) ret+=curG-v[2].front();
		return ret;
	} else if (curG!=-1) {
		if (!v[1].empty()) {
			ll w1=min(v[1].back()-preG,curG-v[1].front());
			rep(i,0,SZ(v[1])-1) w1=min(w1,v[1][i]-preG+curG-v[1][i+1]);
			ret+=w1;
		}
		if (!v[2].empty()) {
			ll w1=min(v[2].back()-preG,curG-v[2].front());
			rep(i,0,SZ(v[2])-1) w1=min(w1,v[2][i]-preG+curG-v[2][i+1]);
			ret+=w1;
		}
		ret=min(ret,curG-preG);
		return ret+curG-preG;
	} else {
		if (!v[1].empty()) ret+=v[1].back()-preG;
		if (!v[2].empty()) ret+=v[2].back()-preG;
		return ret;
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%lld%s",x+i,p);
		if (p[0]=='G') col[i]=0;
		if (p[0]=='R') col[i]=1;
		if (p[0]=='B') col[i]=2;
		v[col[i]].pb(x[i]);
	}
	if (v[0].empty()) {
		ll ret=0;
		if (!v[1].empty()) ret+=v[1].back()-v[1].front();
		if (!v[2].empty()) ret+=v[2].back()-v[2].front();
		printf("%lld\n",ret);
		return 0;
	}
	v[1].clear(); v[2].clear();
	int preG=-1;
	rep(i,0,n) {
		if (col[i]==0) {
			ret+=gao(preG,x[i]);
			v[1].clear(); v[2].clear();
			preG=x[i];
		} else v[col[i]].pb(x[i]);
	}
	ret+=gao(preG,-1);
	printf("%lld\n",ret);
}