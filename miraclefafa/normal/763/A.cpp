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

const int N=501000;
int n,x[N],y[N],c[N],m;
map<int,int> hs;
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",x+i,y+i);
	}
	rep(i,1,n+1) scanf("%d",c+i),hs[i]=0;
	rep(i,1,n) {
		if (c[x[i]]!=c[y[i]]) {
			hs[x[i]]++; hs[y[i]]++;
			m++;
		}
	}
	int q=-1;
	for (auto p:hs) if (p.se==m)  {
		q=p.fi;
		break;
	}
	if (q==-1) puts("NO"); else {
		puts("YES");
		printf("%d\n",q);
	}
}