#include <bits/stdc++.h>
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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int x,y,z,t1,t2,t3;
int main() {
	scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
	int p1=abs(x-y)*t1;
	int p2=abs(x-z)*t2+t3+abs(x-y)*t2+t3+t3;
//	cerr<<p1<<" "<<p2<<endl;
	if (p2<=p1) puts("YES"); else puts("NO");
}