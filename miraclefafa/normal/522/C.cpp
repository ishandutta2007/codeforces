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

const int N=101000;
int _,n,m,a[N],b[N],t[N],r[N];
bool cho[N];
void gao() {
	int fp=0,und=0;
	rep(i,1,m+1) cho[i]=1;
	rep(i,1,n) if (r[i]==1) {
		fp=i; break;
	} else {
		if (t[i]!=0) --a[t[i]];
		else und++;
	}
	if (fp==0) {
		rep(i,1,m+1) putchar(a[i]<=und?'Y':'N');
		puts("");
	} else {
		rep(i,1,m+1) if (a[i]>und) cho[i]=0;
		rep(i,1,m+1) b[i]=a[i];
		int unb=0,mv=1<<30;
		rep(i,fp,n) if (t[i]!=0) cho[t[i]]=0,--b[t[i]];
			else unb++;
		for(int i=1;i<=m;++i)if(cho[i])mv=min(mv,a[i]);
		rep(i,1,m+1) if (cho[i]) {
			putchar('Y');
		} else {
			if (b[i]<=unb+und-mv) putchar('Y'); else putchar('N');
		}
		puts("");
	}
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&m);
		rep(i,1,m+1) scanf("%d",a+i);
		rep(i,1,n) scanf("%d%d",t+i,r+i);
		gao();
	}
}