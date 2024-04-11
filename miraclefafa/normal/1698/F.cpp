#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=510;
int n,a[N],b[N],_;
void solve() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	vector<PII> ans;
	auto gao=[&](int l,int r) {
		reverse(a+l,a+r+1);
		ans.pb(mp(l,r));
	};
	for (int i=1;i<n;i++) {
		if (a[i]!=b[i]) {
			puts("NO");
			return;
		}
		if (a[i+1]!=b[i+1]) {
			int v=b[i+1];
			int found=0;
			for (int j=i+1;j<n;j++) 
				if (a[j]==v&&a[j+1]==a[i]) {
					gao(i,j+1);
					found=1;
					break;
				}
			if (!found) {
				for (int j=i+1;j<n;j++) 
					if (a[j]==a[i]&&a[j+1]==v) {
						bool val=0;
						rep(p1,i,j+1) rep(p2,j+1,n+1)
							if (a[p1]==a[p2]) {
								gao(p1,p2);
								val=1;
								goto find;
							}
						find:;
						if (val) found=2;
						break;
					}
			}
			if (!found) { puts("NO"); return; }
			else if (found==2) --i;
		}
	}
	puts("YES");
	printf("%d\n",SZ(ans));
	for (auto [l,r]:ans) printf("%d %d\n",l,r);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}