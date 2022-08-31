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

int n,ret[101000],ans;
int main() {
	scanf("%d",&n);
	if (n<=2) {
		puts("1");
		rep(i,1,n+1) printf("%d ",1); puts("");
		return 0;
	}
	puts("2");
	rep(i,1,n+1) {
		int p=i+1;
		int cnt=0;
		for (int j=2;j*j<=p;j++) while (p%j==0) p/=j,cnt++;
		if (p!=1) cnt++;
		printf("%d ",(cnt!=1)+1);
	}
}