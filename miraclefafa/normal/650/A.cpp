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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int n,x[N],y[N];
map<int,int> hx,hy;
map<PII,int> h;
ll ans;
ll C(ll x) {
	return x*(x-1)/2;
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",x+i,y+i);
		hx[x[i]]++; hy[y[i]]++;
		h[mp(x[i],y[i])]++;
	}
	for (auto p:hx) ans+=C(p.se);
	for (auto p:hy) ans+=C(p.se);
	for (auto p:h) ans-=C(p.se);
	printf("%lld\n",ans);
}