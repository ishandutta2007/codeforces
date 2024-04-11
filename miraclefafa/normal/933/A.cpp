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

const int N=3010;
int n,a[N],l[N][4],r[N][4],ret;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) {
		l[i][1]=l[i-1][1]+(a[i]==1);
		l[i][2]=max(l[i-1][1],l[i-1][2])+(a[i]==2);
		l[i][2]=max(l[i][1],l[i][2]);
	}
	per(i,1,n+1) {
		r[i][1]=max(r[i+1][1],r[i+1][2])+(a[i]==1);
		r[i][2]=r[i+1][2]+(a[i]==2);
		r[i][1]=max(r[i][1],r[i][2]);
	}
	rep(vr,1,n+1) {
		int p11=0,p12=0,p22=0;
		per(vl,1,vr+1) { // [vl, vr]
			int q11=p11+(a[vl]==1);
			int q12=max(p11,p12)+(a[vl]==2);
			int q22=p22+(a[vl]==2);
			p11=q11; p12=q12; p22=q22;
			ret=max(ret,l[vl-1][1]+p11+r[vr+1][1]);
			ret=max(ret,l[vl-1][1]+p12+r[vr+1][2]);
			ret=max(ret,l[vl-1][2]+p22+r[vr+1][2]);
		}
	}
	printf("%d\n",ret);
}