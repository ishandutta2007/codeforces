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

const int N=1010;
int n,a[N],vis[N];
char s[N][N];
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",a+i);
		--a[i];
	}
	rep(i,0,n) rep(j,0,n) s[i][j]='.';
	int l=n,r=-1;
	rep(i,0,n) if (a[i]!=i) {
		l=min(l,i);
		r=max(r,i);
	}
	if (l>r) {
		printf("%d\n",n);
		rep(i,0,n) puts(s[i]);
		return 0;
	}
	int row=0;
	int pre=0,nxt=a[r];
	rep(i,l,r+1) if (a[i]==r) pre=i;
	a[pre]=a[r]; a[r]=r;
	rep(i,l,r) if (!vis[i]) {
		if (a[i]==i) continue;
		int x=i;
		bool gor=1;
		while (!vis[x]) {
			vis[x]=1;
			if (gor) {
				if (a[x]>x) {
					s[row][x]='/';;
					s[row][a[x]]='/';
				} else {
					s[row][x]='/';
					s[row][r]='/';
					++row;
					s[row][r]='\\';
					s[row][a[x]]='\\';
					gor=0;
				}
			} else {
				if (a[x]<x) {
					s[row][x]='\\';
					s[row][a[x]]='\\';
				} else {
					s[row][x]='\\';
					s[row][i]='\\';
					++row;
					s[row][i]='/';
					s[row][a[x]]='/';
					gor=1;

				}
			}
			x=a[x];
		}
		++row;
	}
	s[row][nxt]='/';
	s[row][r]='/';
	printf("%d\n",n-1);
	per(i,0,n) puts(s[i]);
}