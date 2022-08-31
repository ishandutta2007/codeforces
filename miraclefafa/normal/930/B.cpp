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

const int N=5010;
char s[N];
VI p[30];
int cnt[N][30],n;
double ret;
int main() {
	scanf("%s",s);
	n=strlen(s);
	rep(i,0,n) p[s[i]-'a'].pb(i);
	rep(i,0,26) {
		rep(j,0,n) rep(k,0,26) cnt[j][k]=0;
		for (auto x:p[i]) rep(j,1,n) cnt[j][s[(x+j)%n]-'a']++;
		int mv=0;
		rep(j,1,n) {
			int c=0;
			rep(k,0,26) c+=(cnt[j][k]==1);
			mv=max(mv,c);
		}
		ret+=mv;
	}
	printf("%.10f\n",ret/n);
}