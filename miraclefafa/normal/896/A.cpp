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
ll f[N];
int _,n;
ll k;
string s1="What are you doing while sending \"",s2="\"? Are you busy? Will you send \"",s3="\"?";
string s0="What are you doing at the end of the world? Are you busy? Will you save us?";
char getc(int n,ll k) {
	if (k>=f[n]) return '.';
	else if (n==0) return s0[k];
	else if (k<SZ(s1)) return s1[k];
	else if (k<SZ(s1)+f[n-1]) return getc(n-1,k-SZ(s1));
	else if (k<SZ(s1)+f[n-1]+SZ(s2)) return s2[k-f[n-1]-SZ(s1)];
	else if (k<SZ(s1)+f[n-1]+SZ(s2)+f[n-1]) return getc(n-1,k-SZ(s2)-f[n-1]-SZ(s1));
	else return s3[k-f[n-1]-SZ(s2)-f[n-1]-SZ(s1)];
}
int main() {
	f[0]=SZ(s0);
	rep(i,1,100001) {
		f[i]=min(f[i-1]*2+SZ(s1)+SZ(s2)+SZ(s3),1ll<<60);
	}
	for (scanf("%d",&_);_;_--) {
		scanf("%d%lld",&n,&k); --k;
		printf("%c",getc(n,k));
	}
}