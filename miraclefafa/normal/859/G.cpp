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

const int N=101000;
int n,m;
double dig[N];
char s[N];
VI pr;
int main() {
	scanf("%d",&n); m=n;
	scanf("%s",s);
	rep(i,0,m) dig[i]=s[i]-'0';
	for (int i=2;i<m;i++) if (n%i==0) {
		while (n%i==0) n/=i,pr.pb(i);		
	}
	pr.pb(m);
	for (auto p:pr) {
		for (int i=0;i<m/p;i++) {
			double s=0;
			for (int j=i;j<m;j+=m/p) s+=dig[j];
			s/=p;
			for (int j=i;j<m;j+=m/p) dig[j]-=s;
		}
	}
	rep(i,0,m) {
		if (fabs(dig[i])>=1e-9) { puts("NO"); return 0;}
	}
	puts("YES");
}