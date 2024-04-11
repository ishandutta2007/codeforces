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

typedef long double LD;
int n,x,cnt[110];
LD p[110],mag[110],ret,prob;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&x),p[i]=x*0.01;
	LD prob=0,ret=0;
	rep(i,0,n) {
		cnt[i]+=1;
		ret+=1;
		prob+=log(p[i]);
		mag[i]=log(1-pow(1-p[i],cnt[i]+1))-log(1-pow(1-p[i],cnt[i]));
	}
	rep(r,0,500000) {
		ret+=1-exp(prob);
		int i=max_element(mag,mag+n)-mag;
		cnt[i]++;
		prob+=mag[i];
		mag[i]=log(1-pow(1-p[i],cnt[i]+1))-log(1-pow(1-p[i],cnt[i]));
	}
	printf("%.10f\n",(double)ret);
}