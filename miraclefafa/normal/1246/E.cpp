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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

bitset<2001> sm[(1<<16)+10];
int lev[20],a[20],n,k;
multiset<PII> hs;
bool gaosm(int S,int v,int dep) {
	if (S==0) return v==0;
	rep(j,0,n) if ((S&(1<<j))&&v>=a[j]&&sm[S^(1<<j)][v-a[j]]) {
		lev[j]=dep;
		return gaosm(S^(1<<j),v-a[j],dep);
	}
	return gaosm(S,v*k,dep+1);
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) scanf("%d",a+i);
	sm[0][0]=1;
	rep(S,1,(1<<n)) {
		rep(j,0,n) if (S&(1<<j)) sm[S]|=sm[S^(1<<j)]<<a[j];
		for (int j=2000/k;j>=1;j--) if (sm[S][j*k]) sm[S].set(j);
	}
	if (!sm[(1<<n)-1][1]) {
		puts("NO");
		return 0;
	}
	assert(gaosm((1<<n)-1,1,0));
	puts("YES");
	rep(i,0,n) {
	//	printf("gg %d\n",lev[i]);
		hs.insert(mp(-lev[i],a[i]));
	}
	rep(i,0,n-1) {
		auto p1=hs.begin(); hs.erase(p1);
		auto p2=hs.begin(); hs.erase(p2);
		assert(p1->fi==p2->fi);
		printf("%d %d\n",p1->se,p2->se);
		auto p3=mp(p1->fi,p1->se+p2->se);
		while (p3.se%k==0) p3.se/=k,p3.fi++;
		//printf("gg %d %d\n",p3.fi,p3.se);
		hs.insert(p3);
	}
}