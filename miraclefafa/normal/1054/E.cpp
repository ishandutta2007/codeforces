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

const int N=310;
int n,m;
deque<int> a[N][N],b[N][N],aaa[N][N];
char s[101000];
vector<VI> ans,ans2;

void move1(int p,int q,int r,int s) {
	if (p==r&&q==s) assert(0);
	int x=a[p][q].back();
	a[p][q].pop_back(); a[r][s].push_front(x);
	if (p==r||q==s) {
		ans.pb(VI{p,q,r,s});
	} else {
		if (a[p][s].empty()) {
			ans.pb(VI{p,q,p,s});
			ans.pb(VI{p,s,r,s});
		} else {
			assert(a[r][q].empty());
			ans.pb(VI{p,q,r,q});
			ans.pb(VI{r,q,r,s});
		}
	}
}

void move2(int p,int q,int r,int s) {
	if (p==r&&q==s) assert(0);
	int x=b[p][q].front();
	b[p][q].pop_front(); b[r][s].push_back(x);
	if (p==r||q==s) {
		ans2.pb(VI{r,s,p,q});
	} else {
		if (b[p][s].empty()) {
			ans2.pb(VI{p,s,p,q});
			ans2.pb(VI{r,s,p,s});
		} else {
			assert(b[r][q].empty());
			ans2.pb(VI{r,q,p,q});
			ans2.pb(VI{r,s,r,q});			
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) rep(j,0,m) {
		scanf("%s",s);
		int l=strlen(s);
		rep(k,0,l) {
			a[i][j].pb(s[k]-'0');
			aaa[i][j].pb(s[k]-'0');
		}
	}
	rep(i,0,n) rep(j,0,m) {
		scanf("%s",s);
		int l=strlen(s);
		rep(k,0,l) b[i][j].pb(s[k]-'0');
	}
	while (!a[0][0].empty()) {
		move1(0,0,0,1);
	}
	while (!a[1][1].empty()) {
		move1(1,1,0,1);
	}

	rep(i,0,n) rep(j,0,m) {
		if (mp(i,j)==mp(0,0)||mp(i,j)==mp(1,1))
			continue;
		while (!a[i][j].empty()) {
			move1(i,j,a[i][j].back(),a[i][j].back());
		}
	}

	while (!b[0][0].empty()) {
		move2(0,0,0,1);
	}
	while (!b[1][1].empty()) {
		move2(1,1,0,1);
	}

	rep(i,0,n) rep(j,0,m) {
		if (mp(i,j)==mp(0,0)||mp(i,j)==mp(1,1))
			continue;
		while (!b[i][j].empty()) {
			move2(i,j,b[i][j].front(),b[i][j].front());
		}
	}
	reverse(all(ans2));
	for (auto p:ans2) ans.pb(p);
	printf("%d\n",SZ(ans));
	for (auto p:ans) printf("%d %d %d %d\n",p[0]+1,p[1]+1,p[2]+1,p[3]+1);
/*	for (auto p:ans) {
		assert(p[0]==p[2]||p[1]==p[3]);
		if (p[0]==p[2]&&p[1]==p[3]) assert(0);
		assert(!aaa[p[0]][p[1]].empty());
		int x=aaa[p[0]][p[1]].back();
		aaa[p[0]][p[1]].pop_back();
		aaa[p[2]][p[3]].push_front(x);

		rep(i,0,n) {
			rep(j,0,m) {
				printf("|");
				for (auto p:aaa[i][j]) printf("%d",p);
				printf("| ");
			}
			puts("");
		}
		puts("----");
	}*/
}