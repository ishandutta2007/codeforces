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

const int N=201000;
int n,a[N],sm[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,2,n+1) {
		for (int l=1;l<=n;l++) {
			int p=(i-2)/l+1;
			int r=(p==1)?n:(i-2)/(p-1);
			if (a[i]<a[p]) sm[l]++,sm[r+1]--;
			l=r;
		}
	}
	rep(i,1,n+1) sm[i]+=sm[i-1];
	rep(i,1,n) printf("%d ",sm[i]);
}