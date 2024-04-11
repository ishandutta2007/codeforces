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

int n;
vector<vector<int> > ret;
void add(VI a) {
	ret.pb(a);
}
int main() {
	scanf("%d",&n);
	if (n%2==1) {
		add({1,2,3});
		add({1,2,3});
		for (int i=4;i<=n;i+=2) {
			add({1,i,i+1});
			add({1,i,i+1});
			for (int j=2;j<i;j+=2) {
				add({j,i+1,j+1,i});
				add({j,i+1,j+1,i});
			}
		}
	} else {
		add({1,2,3,4});
		add({1,2,4,3});
		add({1,3,2,4});
		for (int i=5;i<=n;i+=2) {
			add({1,i,i+1});
			add({2,i,i+1});
			add({1,i+1,2,i});
			for (int j=3;j<i;j+=2) {
				add({j,i+1,j+1,i});
				add({j,i+1,j+1,i});
			}
		}
	}
	printf("%d\n",SZ(ret));
	for (auto p:ret) {
		printf("%d",SZ(p));
		for (auto q:p) printf(" %d",q);
		puts("");
	}
}