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

char s[50100];
int n,cnt[10];
int main() {
	scanf("%s",s);
	n=strlen(s);
	rep(i,0,n-1) {
		if (s[i]>s[i+1]) {
			puts("NO");
			return 0;
		}
	}
	rep(i,0,n) cnt[s[i]-'a']++;
	if (cnt[0]>=1&&cnt[1]>=1&&(cnt[2]==cnt[0]||cnt[2]==cnt[1])) {
		puts("YES");
	} else puts("NO");
}