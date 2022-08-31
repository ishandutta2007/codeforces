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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,val[1010],perm[10],id[10],f[10];
ll ff[1100];
map<VI,int> cache;

int tcnt;

int myquery(VI c) {
	sort(all(c));
	if (cache.count(c)) return cache[c];
//	tcnt++;
	printf("? %d %d %d\n",c[0],c[1],c[2]);
	fflush(stdout);
	int x=0;
	scanf("%d",&x);
//	x=min(min(ff[c[0]],ff[c[1]]),ff[c[2]])+max(max(ff[c[0]],ff[c[1]]),ff[c[2]]);
	return cache[c]=x;
}

void query(VI id) {
	cache.clear();
	rep(i,0,5) perm[i]=i;
	while (1) {
		auto myQ=[&](int a,int b,int c) {
			return myquery(VI{id[perm[a]],id[perm[b]],id[perm[c]]});
		};
		int p02=myQ(0,1,2),p13=myQ(1,2,3),p24=myQ(2,3,4),p03=myQ(0,1,3),p14=myQ(1,2,4);
		ll ss=(ll)p02+p13+p24+p03+p14;
		if (ss%2!=0) {
			goto incorrect;
		}
		ss/=2;
		f[0]=ss-p13-p24; f[1]=ss-p03-p24; f[2]=ss-p03-p14; f[3]=ss-p02-p14; f[4]=ss-p02-p13;
		rep(i,0,4) if (f[i]>f[i+1]) {
			goto incorrect;
		}
		rep(i,0,5) rep(j,i+1,5) rep(k,j+1,5) {
			if (f[i]+f[k]!=myQ(i,j,k)) {
				goto incorrect;
			}
		}
		rep(i,0,5) if (f[i]<0||f[i]>1000000000) goto incorrect;
		rep(i,0,5) val[id[perm[i]]]=f[i];
		incorrect:;
		if (!next_permutation(perm,perm+5)) break;
	}
}

int main() {
	scanf("%d",&n);
//	rep(i,1,n+1) ff[i]=rand()%1000000001;
	for (int i=1;i<=n;i+=5) {
		if (i+4<=n) {
			query(VI{i,i+1,i+2,i+3,i+4});
		} else {
			query(VI{n-4,n-3,n-2,n-1,n});
		}
	}
	printf("!");
	rep(i,1,n+1) {
		printf(" %d",val[i]);
//		assert(val[i]==ff[i]);
	}
	puts("");
	fflush(stdout);
//	fprintf(stderr,"tcnt %d %d\n",tcnt,4*n);
}