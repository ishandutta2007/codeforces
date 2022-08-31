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

int n;
char s[10100];
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	rep(i,0,n) {
		for (int d=1;i+4*d<n;d++) if (s[i]=='*'&&s[i+d]=='*'&&s[i+d+d]=='*'&&s[i+d*3]=='*'&&s[i+d*4]=='*') 
			return puts("yes"),0;
	}
	puts("no");
}