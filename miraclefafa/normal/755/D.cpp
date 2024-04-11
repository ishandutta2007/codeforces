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
int n,k,t,c[N];
int query(int x) { int s=0; for (;x;x-=x&-x) s+=c[x]; return s;}
void modify(int x,int s) { for (;x<=n;x+=x&-x) c[x]+=s; t+=s; }
int Query(int x) {
	if (x>=n) return query(x-n)+t; else if (x<0) return query(x+n)-t; else return query(x);
}
int main() {
	scanf("%d%d",&n,&k);
	k=min(k,n-k);
	int x=1; ll cnt=1;
	rep(i,1,n+1) {
		int b=Query(x+k-1)-Query(x-k);
		cnt+=b+1;
		modify(x,1);
		x=(x+k-1)%n+1;
		printf("%lld ",cnt);
	}
}