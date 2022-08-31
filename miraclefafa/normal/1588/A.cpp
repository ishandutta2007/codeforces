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

const int N=1010;
int _,x,a[N],b[N],c[N],n;
bool solve() {
	scanf("%d",&n);
	rep(i,0,201) a[i]=b[i]=c[i]=0;
	rep(i,0,n) {
		scanf("%d",&x);
		a[x+100]++;
	}
	rep(i,0,n) {
		scanf("%d",&x);
		b[x+100]++;
	}
	rep(i,0,201) {
		if (a[i]+c[i]<b[i]) return 0;
		if (a[i]+c[i]>=b[i]) {
			int d=a[i]+c[i]-b[i];
			if (a[i]<d) return 0;
			a[i]-=d;
			c[i+1]+=d;
		}
	}
	return 1;
}

int main() {
	for (scanf("%d",&_);_;_--) {
		puts(solve()?"YES":"NO");
	}
}