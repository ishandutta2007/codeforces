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
int n,a[N],l[N],r[N],s[N],v[N];
void gao(int *l) {
	int top=0; s[top]=0;
	rep(i,1,n+1) {
		while (a[i]<=a[s[top]]) --top;
		l[i]=s[top];
		s[++top]=i;
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	gao(l);
	reverse(a+1,a+n+1);
	gao(r);
	rep(i,1,n+1) r[i]=n+1-r[i];
	reverse(r+1,r+n+1);
	reverse(a+1,a+n+1);
	rep(i,1,n+1) {
		v[r[i]-l[i]-1]=max(v[r[i]-l[i]-1],a[i]);
	}
	per(i,1,n+1) v[i]=max(v[i],v[i+1]);
	rep(i,1,n+1) printf("%d ",v[i]);
}