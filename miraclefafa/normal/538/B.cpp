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


int n;
VI vec;
int main() {
	scanf("%d",&n);
	while (n) {
		vec.pb(n%10);
		n/=10;
	}
	int k=*max_element(all(vec));
	printf("%d\n",k);
	rep(i,1,k+1) {
		int x=0;
		per(j,0,SZ(vec)) if (vec[j]>=i) x=x*10+1; else x=x*10;
		printf("%d ",x);
	}
}