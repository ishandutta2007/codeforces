#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int N=301000;
char s[N],t[N],ret[N];
int n;
int main() {
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	sort(s+1,s+n+1);
	sort(t+1,t+n+1);
	reverse(t+1,t+n+1);
	int h1=1,t1=(n+1)/2,h2=1,t2=n/2,h3=1,t3=n;
	rep(i,1,n+1) {
		if (i%2==1) { // A
			if (s[h1]<t[h2]) ret[h3++]=s[h1++];
			else ret[t3--]=s[t1--];
		} else {
			if (s[h1]<t[h2]) ret[h3++]=t[h2++];
			else ret[t3--]=t[t2--];
		}
	}
	puts(ret+1);
}