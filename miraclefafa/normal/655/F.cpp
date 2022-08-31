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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1010000;
int phi[N],ans,cnt[N],n,k,q,x;
ll comb[N],inr[N];
VI d[N];
void modify(int x) {
	cnt[x]++;
	ans=(ans+inr[cnt[x]]*phi[x])%mod;
}
int main() {
	scanf("%d%d%d",&n,&k,&q);
	comb[k]=1;
	rep(i,k+1,n+q+1) {
		comb[i]=comb[i-1]*i%mod*powmod(i-k,mod-2)%mod;
	}
	rep(i,1,n+q+1) {
		inr[i]=comb[i]-comb[i-1];
		if (inr[i]<0) inr[i]+=mod;
	}
	rep(i,1,1000001) phi[i]=i,d[i].pb(i);
	rep(i,1,1000001) for (int j=i+i;j<=1000000;j+=i) phi[j]-=phi[i],d[j].pb(i);
	rep(i,0,n) {
		scanf("%d",&x);
		for (auto p:d[x]) modify(p);
	}
	rep(i,0,q) {
		scanf("%d",&x);
		for (auto p:d[x]) modify(p);
		printf("%d\n",ans);
	}

}