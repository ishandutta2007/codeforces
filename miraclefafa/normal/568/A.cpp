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

const int N=10000000;
int d[20],pr[N+10];
ll p,q;
bool pal(int x) {
	int tot=0;
	while (x) d[tot++]=x%10,x/=10;
	rep(i,0,tot) if (d[i]!=d[tot-1-i]) return 0;
	return 1;
}
int main() {
	scanf("%I64d%I64d",&p,&q);
	for (int i=2;i<=N;i++) if (!pr[i]) {
		for (int j=2*i;j<=N;j+=i) pr[j]=1;
	}
	for (int i=2;i<=N;i++) {
		pr[i]=!pr[i];
		pr[i]+=pr[i-1];
	}
	int x=0,ans=1;
	for (int i=1;i<=N;i++) {
		x+=pal(i); 
		if (p*x>=q*pr[i]) ans=i; 
	}
	printf("%d\n",ans);
}