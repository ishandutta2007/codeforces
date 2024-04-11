#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=501000;
int n,k;
bool mark[30];
char s[N],t[10];
void solve() {
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%d",&k);
	rep(i,0,26) mark[i]=false;
	rep(i,0,k) {
		scanf("%s",t);
		mark[t[0]-'a']=1;
	}
	int len=0,ans=0;
	rep(i,0,n) {
		if (mark[s[i]-'a']) ans=max(ans,len),len=1;
		else len++;
		//printf("%d %d\n",i,len);
	}
	printf("%d\n",ans);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}