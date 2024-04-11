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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010;
int a[N],_;
void solve() {
	int n;
	map<int,int> cnt;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",a+i);
		cnt[a[i]]++;
	}
	for (int i=0;i<n;i++) {
		if (cnt[i]) {
			printf("%d ",i);
			cnt[i]--;
		} else {
			break;
		}
	}
	for (int i=0;i<=100;i++) for (int j=0;j<cnt[i];j++) printf("%d ",i);
	puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}