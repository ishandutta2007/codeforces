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

int n,k,x,f,a[1030],b[1030];
int main() {
	scanf("%d%d%d",&n,&k,&x);
	rep(i,0,n) {
		scanf("%d",&f);
		a[f]++;
	}
	rep(i,0,k) {
		rep(j,0,1024) b[j]=a[j],a[j]=0;
		int v=0;
		rep(j,0,1024) {
			int c=(b[j]+1-v)/2;
			a[j^x]+=c;
			a[j]+=b[j]-c;
			v=(v+b[j])%2;
		}
	}
	int mx=0,mn=1024;
	rep(i,0,1024) if (a[i]) mx=max(mx,i),mn=min(mn,i);
	printf("%d %d\n",mx,mn);
}