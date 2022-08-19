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

set<string> hs;
int n,m,w;
char s[10100];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%s",s);
		hs.insert(string(s));
	}
	rep(i,0,m) {
		scanf("%s",s);
		if (hs.count(string(s))) w++;
	}
	n-=w; m-=w;
	n+=(w+1)/2; m+=w/2;
	if (n>m) puts("YES"); else puts("NO");
}