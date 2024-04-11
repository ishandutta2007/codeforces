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

const int N=1010000;
int n,p[N],geq,le,cur[N*2],ansv;
ll sum,ans;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",p+i),--p[i];
	rep(i,0,n) {
		sum+=abs(p[i]-i);
		if (p[i]>=i) geq++; else le++;
		if (p[i]>=i) {
			// after p[i]-i round
			cur[p[i]-i]++;
		}
		// 0 p[i]
	}
	ans=sum; ansv=0;
	rep(i,0,n-1) {
		geq-=cur[i]; le+=cur[i];
//		printf("%d %d\n",geq,le);
		sum=sum-geq+le;
		sum=sum-abs(p[n-i-1]-n)+p[n-i-1];
//		printf("ff %lld %d\n",sum,i+1);
		if (sum<ans) ans=sum,ansv=i+1;
		le--; geq++;
//		printf("gg %d %d %d\n",geq,le,p[n-i-1]+i);
		cur[p[n-i-1]+i+1]++;
	}
	printf("%lld %d\n",ans,ansv);
}