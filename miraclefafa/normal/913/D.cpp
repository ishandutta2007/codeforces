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
int n,T,p,t;
vector<PII> v[N];
priority_queue<PII> q;
int main() {
	scanf("%d%d",&n,&T);
	rep(i,0,n) {
		scanf("%d%d",&p,&t);
		v[p].pb(mp(t,i));
	}
	ll s=0;
	per(i,0,n+1) {
		for (auto u:v[i]) q.push(u),s+=u.fi;
		while (q.size()>i) {
			s-=q.top().fi; q.pop();
		}
		if (q.size()==i&&s<=T) {
			printf("%d\n%d\n",i,i);
			while (!q.empty()) printf("%d ",q.top().se+1),q.pop();
			puts("");
			return 0;
		}
	}
}