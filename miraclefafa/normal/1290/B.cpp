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
int ps[28][N],_,l,r;
char s[N];
bool check(int l,int r) {
	if (l==r) return 1;
	int dd=0;
	rep(i,0,26) dd+=(ps[i][r]-ps[i][l-1]!=0);
	if (dd>=3) return 1;
	if (dd==2&&s[l]!=s[r]) return 1;
	return 0;
}

int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,0,26) {
		rep(j,1,n+1) ps[i][j]=ps[i][j-1]+(s[j]==i+'a');
	}
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&l,&r);
		puts(check(l,r)?"Yes":"No");
	}

}