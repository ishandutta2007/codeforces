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

int n,x,mask,bit,bit2,b1,b2,b3;
char op[10];
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s%d",op,&x);
		if (op[0]=='|') {
			rep(i,0,10) if (x&(1<<i)) {
				mask|=(1<<i);
				bit|=(1<<i);
			}
		} else if (op[0]=='&') {
			rep(i,0,10) if ((x&(1<<i))==0) {
				mask|=(1<<i);
				bit&=(1<<10)-1-(1<<i);
			}
		}  else if (op[0]=='^') {
			rep(i,0,10) if ((x&(1<<i))) {
				if (mask&(1<<i)) bit^=(1<<i);
				bit2^=(1<<i);
			}
		}
	}
	puts("3");
	b1=1023;
	rep(i,0,10) if (mask&(1<<i)) {
		if (bit&(1<<i)) b2+=(1<<i);
		else b1-=(1<<i);
	} else if (bit2&(1<<i)) b3+=(1<<i);
	printf("& %d\n| %d\n^ %d\n",b1,b2,b3);
}