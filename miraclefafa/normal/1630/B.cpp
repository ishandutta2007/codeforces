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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,k,_,a[N];
VI v[N];

void solve() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) v[i].clear();
	rep(i,1,n+1) {
		scanf("%d",a+i);
		v[a[i]].pb(i);
	}
	int y=0;
	int mv=n+1;
	PII ansp;
	int s=-n;
	for (int x=1;x<=n;x++) {
		while (s<k&&y<=n) {
			++y;
			if (y>n) break;
			s+=2*SZ(v[y]);
		}
		if (y>n) break;
		if (y-x<=mv) mv=y-x,ansp={x,y};
		s-=2*SZ(v[x]);
	}
	int x=ansp.fi;
	y=ansp.se;
	printf("%d %d\n",x,y);
	int pre=0,cnt=0;
	int pos=0;
	for (int i=1;i<k;i++) {
		pos+=1;
		while (1) {
			if (a[pos]>=x&&a[pos]<=y) {
				cnt++;
			} else cnt--;
			if (cnt==i) break;
			pos++;
		}
		printf("%d %d\n",pre+1,pos);
		pre=pos;
	}
	printf("%d %d\n",pre+1,n);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}