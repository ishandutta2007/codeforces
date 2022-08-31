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
char s[10100];
int n,win[N][N];
int main() {
	scanf("%s",s);
	n=strlen(s);
	rep(i,0,n) {
		int cnt=0;
		rep(j,i,n) {
			if (s[j]=='('||s[j]=='?') cnt++;
				else cnt--;
			if (cnt>=0) win[i][j]++;
			else break;
		}
	}
	per(i,0,n) {
		int cnt=0;
		per(j,0,i+1) {
			if (s[j]==')'||s[j]=='?') cnt++;
				else cnt--;
			if (cnt>=0) win[j][i]++;
			else break;
		}
	}
	int cnt=0;
	rep(i,0,n) rep(j,i,n) if ((i+j)%2==1&&win[i][j]==2) cnt++;
	printf("%d\n",cnt);
}