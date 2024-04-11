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

const int N=201000;
int n,m,cnt[N],col[N],cur[N],tot,l,ans=1e9;
set<int> sta;
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%d",col+i),col[i]--;
	rep(i,0,m) scanf("%d",&cnt[i]),tot+=cnt[i];
	rep(i,0,m) if (cnt[i]>0) sta.insert(i);
	rep(r,0,n) {
		int w=col[r];
		cur[w]++;
		if (cur[w]==cnt[w]) sta.erase(w);
		while (sta.empty()) {
//			printf("%d %d\n",l,r);
			ans=min(ans,r-l+1-tot);
			w=col[l];
			--cur[w];
			if (cur[w]==cnt[w]-1) sta.insert(w);
			l++;
		}
	}
	if (ans>=5e8) ans=-1;
	printf("%d\n",ans);
}