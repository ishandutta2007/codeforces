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

int n,m;
int main() {
	scanf("%d%d",&n,&m);
	int ans=0,p2=0,p3=0,p6=0;
	while (1) {
		if (max(n-p2,0)+max(m-p3,0)<=p6) break;
		ans++;
		if (ans%6==0) p6++;
		else if (ans%2==0) p2++;
		else if (ans%3==0) p3++;
	}
	printf("%d\n",ans);
}