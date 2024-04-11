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

void Z(char *a,int *nt,int n) {
	nt[0]=n;
	for (int i=1,j=0,k=0;i<n;i+=k,j=max(0,j-k)) {
		for (;i+j<n&&a[j]==a[i+j];++j);
		for (nt[i]=j,k=1;k<=j&&nt[k]!=j-k;k++) nt[i+k]=min(nt[k],j-k);
	}
}
const int N=1010000;
int nt[N],n,k,c[N];
char s[N];
void cover(int l,int r) { c[l]++; c[r+1]--;}
int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	Z(s,nt,n);
	for (int i=k;i<=n;i+=k) if (nt[i/k]>=i-i/k) {
		cover(i,min(i+min(nt[i],i/k),n));
	}
	rep(i,1,n+1) c[i]+=c[i-1];
	rep(i,1,n+1) putchar(c[i]?'1':'0');
}