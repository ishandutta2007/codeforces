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

const int N=201000;
int n,p[N],vis[N],rt,cnt,T;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",p+i);
		if (p[i]==i) rt=i;
	}
	rep(i,1,n+1) if (!vis[i]) {
		T++;
		int x=i;
		while (!vis[x]) {
			vis[x]=T;
			x=p[x];
		}
		if (vis[x]==T) {
			if (!rt) {
				rt=x; p[x]=x;
				cnt++;
			}
			if (x!=rt) {
				p[x]=rt;
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	rep(i,1,n+1) printf("%d ",p[i]);
}