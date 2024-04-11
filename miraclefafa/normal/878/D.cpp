#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
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

const int N=101000;
bitset<4096> q[N];
vector<PII> v[N];
int n,k,Q,ty,p1,p2,w,b[20][N];
int main() {
	scanf("%d%d%d",&n,&k,&Q);
	rep(i,0,k) {
		rep(j,0,n) scanf("%d",&b[i][j]),v[j].pb(mp(b[i][j],i));
		rep(j,0,4096) q[i][j]=(j>>i)&1;
	}
	rep(j,0,n) sort(all(v[j]));
	w=k;
	rep(i,0,Q) {
		scanf("%d%d%d",&ty,&p1,&p2);
		--p1; --p2;
		if (ty!=3) {
			q[w++]=(ty==1)?(q[p1]|q[p2]):(q[p1]&q[p2]);
		} else {
			int s=0;
			per(j,0,k) {
				s|=(1<<v[p2][j].se);
				if (q[p1][s]) {
					printf("%d\n",v[p2][j].fi);
					break;
				}
			}
		}
	}
}