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

int m,n,k,tot;
char s[3010];
int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	vector<VI> ps=vector<VI>(k,vector<int>());
	while (1) {
		VI step;
		rep(i,0,n-1) if (s[i]=='R'&&s[i+1]=='L') step.pb(i),tot++;
		if (step.empty()) break;
		if (m>=k) {
			puts("-1");
			return 0;
		}
		ps[m++]=step;
		for (auto x:step) swap(s[x],s[x+1]);
	}
	if (k>tot) {
		puts("-1");
		return 0;
	}
	//printf("xx %d %d\n",tot,m);
	int fs=m-1;
	per(i,0,k) {
		if (ps[fs].empty()) fs--;
		if (!ps[i].empty()) break;
		ps[i]=VI{ps[fs].back()};
		ps[fs].pop_back();
	}
	rep(i,0,k) {
		printf("%d",SZ(ps[i]));
		for (auto x:ps[i]) printf(" %d",x+1);
		puts("");
	}
}