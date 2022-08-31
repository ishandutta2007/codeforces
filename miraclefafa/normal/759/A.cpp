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
int n,f[N],p[N],b,v,cnt;
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) f[i]=i;
	rep(i,1,n+1) {
		scanf("%d",p+i);
		if (find(i)==find(p[i])) cnt++; else f[find(i)]=find(p[i]);
	}
	rep(i,1,n+1) scanf("%d",&b),v^=b;
	if (cnt==1) cnt-=1;
	if (v==0) cnt+=1;
	printf("%d\n",cnt);
}