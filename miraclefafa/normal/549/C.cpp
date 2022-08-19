#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int dp[40][40][40][2];
int solve(int a,int b,int k,int op) {
	if (a+b==k) {
		return dp[a][b][k][op]=(a%2==op);
	} else {
		if (dp[a][b][k][op]!=-1) return dp[a][b][k][op];
		dp[a][b][k][op]=1;
		if (a>0) dp[a][b][k][op]&=solve(a-1,b,k,op^1);
		if (b>0) dp[a][b][k][op]&=solve(a,b-1,k,op^1);
		dp[a][b][k][op]^=1;
		return dp[a][b][k][op];
	}
}
int check(int a,int b,int k) {
	if (a+k<=b) return 0;
	else if (b==0) return k%2;
	else if (k==0) return 0;
	else if (a+b==k) return a%2;
	else if ((a+b)%2==0) return k%2;
	else {
		if (k<=a-b) return (a+b+k+1)%2;
		else return (a+b+k)%2;
	}
}
int n,k,x,a,b;
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) {	
		scanf("%d",&x);
		if (x%2==0) b++; else a++;
	}
	puts(check(a,b,k)?"Stannis":"Daenerys");
}