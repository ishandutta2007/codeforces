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

int p[10],q[10];
int main() {
	scanf("%d%d%d%d",p+0,p+1,p+2,p+3);
	rep(st,0,4) {
		rep(i,0,4) q[i]=p[i];
		int x=st;
		if (q[x]==0) continue;
		VI seq;
		while (1) {
			seq.pb(x); q[x]--;
			if (x&&q[x-1]) {
				x--;
			} else if (x!=3&&q[x+1]) {
				x++;
			} else break;
		}
		if (q[0]==0&&q[1]==0&&q[2]==0&&q[3]==0) {
			puts("YES");
			for (auto x:seq) printf("%d ",x); puts("");
			return 0;
		}
	}	
	puts("NO");
}