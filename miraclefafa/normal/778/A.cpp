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

const int N=201000;
int vis[N],p[N],n,m;
VI ch[30];
char s[N],t[N];
bool check(int x) {
	rep(i,1,n+1) vis[i]=0;
	rep(i,1,x+1) vis[p[i]]=1;
	rep(i,0,26) ch[i].clear();
	rep(i,1,n+1) if (!vis[i]) {
		ch[s[i]-'a'].pb(i);
	}
	int pos=1;
	rep(i,0,m) {
		int w=t[i]-'a';
		auto q=lower_bound(all(ch[w]),pos);
		if (q==ch[w].end()) return 0;
		pos=*q+1;
	}
	return 1;
}
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%s",t);
	m=strlen(t);
	rep(i,1,n+1) scanf("%d",p+i);
	int l=0,r=n;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (check(md)) l=md; else r=md;
	}
	printf("%d\n",l);
}