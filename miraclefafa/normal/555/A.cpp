#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int n,k,m,p[101000];
int main() {
	scanf("%d%d",&n,&k);
	int cnt=0;
	rep(i,0,k) {
		scanf("%d",&m);
		rep(j,0,m) scanf("%d",p+j);
		if (p[0]!=1) cnt+=m-1;
		else {
			rep(j,0,m-1) if (p[j]+1!=p[j+1]) {
				cnt+=m-j-1;
				break;
			}
		}
	}
	printf("%d\n",2*cnt+k-1);
}