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

const int N=1010000;
char s[N],t[2*N];
int n,k,x,ml;
set<int> hs;
int main() {
	scanf("%d",&n);
	rep(i,1,2000001) hs.insert(i);
	rep(j,0,n) {
		scanf("%s",s);
		int l=strlen(s);
		scanf("%d",&k);
		rep(j,0,k) {
			scanf("%d",&x);
			while (1) {
				auto it=hs.lower_bound(x);
				if (it==hs.end()||*it-x>=l) {
					break;
				}
				ml=max(*it,ml);
				t[*it]=s[*it-x];
				hs.erase(it);
			}
		}
	}
	rep(i,1,ml+1) if (!t[i]) t[i]='a';
	puts(t+1);
}