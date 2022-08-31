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

const int M=1000000000;
char s[30];
bool answer(int x,int y) {
	printf("%d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='b';
}
int n;
int main() {
	scanf("%d",&n);
	bool ty=answer(0,M/2);
	int vl=0,vr=M;
	int l=1,r=M;
	rep(i,1,n) {
		int mid=(l+r)>>1;
		bool ty2=answer(mid,M/2);
		if (ty2==ty) {
			vl=max(vl,mid);
			l=mid+1;
		} else {
			vr=min(vr,mid);
			r=mid-1;
		}
	}
	printf("%d %d %d %d\n",vl,0,vr,M);
}