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

int _,x,y,a,b;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if (a==b) {
			if (x!=y) { puts("-1"); continue; }
			else { puts("0"); continue; }
		} else if (a==0) {
			if (x!=0) { puts("-1"); continue; }
			else { puts("0"); continue; }
		} else {
			ll t=max((x+a-1)/a,(y+b-1)/b);
			t=max(t,(ll)(y-x+b-a-1)/(b-a));
			printf("%lld\n",t*b-y);
		}
	}
}