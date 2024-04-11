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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=110;
int n,p[N][N],val[N];
VI cand;
bool check() {
	rep(i,0,n) rep(j,0,n) if (i!=j&&min(val[i],val[j])!=p[i][j]) return 0;
	rep(i,0,n) printf("%d ",val[i]);
	return 1;
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) rep(j,0,n) {
		scanf("%d",&p[i][j]);
		if (p[i][j]==n-1) cand.pb(i);
	}
	for (auto q:cand) {
		rep(i,0,n) val[i]=p[q][i];
		val[q]=n;
		if (check()) return 0;
	}
}