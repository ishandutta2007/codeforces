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

int n;
char s[1010000];
VI bl;
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	int pr=0;
	rep(i,0,n) {
		if (i!=0&&s[i]!=s[i-1]) { bl.pb(pr); pr=0;}
		pr++;
	}
	bl.pb(pr);
	int c2=0,c3=0;
	rep(i,0,SZ(bl)) {
		c2+=bl[i]>=2;
		c3+=bl[i]>=3;
	}
	if (c3>=1||c2>=2) printf("%d\n",SZ(bl)+2);
	else if (c2>=1) printf("%d\n",SZ(bl)+1);
	else printf("%d\n",SZ(bl));
}