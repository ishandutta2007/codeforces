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
int n,s,h[N],sh[N],wr,emp[N],ret,e,wr2;
int main() {
	scanf("%d%d",&n,&s);
	rep(i,1,n+1) scanf("%d",h+i);
	if (h[s]!=0) h[s]=0,wr++;
	rep(i,1,n+1) if (i!=s) {
		if (h[i]==0) h[i]=n+1,wr2++;
	}
	rep(i,1,n+1) sh[h[i]]++;
	rep(i,1,n+1) if (sh[i]==0) {
		emp[i]=1;
	}
	rep(i,1,n+1) sh[i]+=sh[i-1];
	rep(i,0,n) {
		if (emp[i]) e++;
		int rem=n-wr2-sh[i];
		if (rem+wr2>=e) ret=max(ret,sh[i]);
		else ret=max(ret,sh[i]-(e-rem-wr2));
	}
	printf("%d\n",n-(ret-wr));
}