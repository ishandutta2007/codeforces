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

int o,p,q;
int main() {
	scanf("%d",&o);
	scanf("%d:%d",&p,&q);
	if (o==12) {
		int mv=10,md=0;
		rep(c,1,13) {
			int v=((p%10)!=(c%10))+((p/10)!=(c/10));
			if (v<mv) {
				mv=v; md=c;
			}
		}
		printf("%02d:",md);
	} else {
		int mv=10,md=0;
		rep(c,0,24) {
			int v=((p%10)!=(c%10))+((p/10)!=(c/10));
			if (v<mv) {
				mv=v; md=c;
			}
		}
		printf("%02d:",md);
	}
	int mv=10,md=0;
	rep(c,0,60) {
		int v=((q%10)!=(c%10))+((q/10)!=(c/10));
		if (v<mv) {
			mv=v; md=c;
		}
	}
	printf("%02d\n",md);
}