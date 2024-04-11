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

int n,m,col[110];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%d",col+i),col[i]--;
	VI cnt=VI(m,0);
	rep(i,0,m) scanf("%d",&cnt[i]);
	rep(i,0,n) {
		VI w(m,0);
		rep(j,i,n) {
			w[col[j]]++;
			if (w==cnt) {
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
}