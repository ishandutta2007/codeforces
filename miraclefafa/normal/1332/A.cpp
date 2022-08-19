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

#define y1 afadsf

int _,a,b,c,d,x,y,x1,y1,x2,y2;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
		x=x-a+b; y=y-c+d;
		if (x>=x1&&x<=x2&&y>=y1&&y<=y2)
			if (x1==x2&&a!=0) puts("NO");
			else if (y1==y2&&c!=0) puts("NO");
			else puts("YES");
		else {
			puts("NO");
		}
	}
}