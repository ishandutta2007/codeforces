#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=10100000;
map<char,char> hs;
int n,t2[N],t1[N];
char s1[N],s2[N];
void Z(char *a,int *nt,int n) {
	nt[0]=n;
	for (int i=1,j=0,k=0;i<n;i+=k,j=max(0,j-k)) {
		for (;i+j<n&&a[j]==a[i+j];++j);
		for (nt[i]=j,k=1;k<=j&&nt[k]!=j-k;k++) nt[i+k]=min(nt[k],j-k);
	}
}
void Z_match(char *a,int *nt,int n,char *b,int *ex,int m) {
	for (int i=0,j=0,k=0;i<m;i+=k,j=max(0,j-k)) {
		for (;j<n && i+j<m&&a[j]==b[i+j];++j);
		for (ex[i]=j,k=1;k<=j&&k+nt[k]!=j;k++) ex[i+k]=min(nt[k],j-k);
	}
}

int main() {
	scanf("%d",&n);
	scanf("%s%s",s1,s2);
	n--; hs['N']='S'; hs['E']='W'; hs['W']='E'; hs['S']='N';
	rep(i,0,n) s2[i]=hs[s2[i]];
	reverse(s2,s2+n);
	Z(s2,t2,n);
	Z_match(s2,t2,n,s1,t1,n);
	rep(i,0,n) if (t1[i]+i==n) {
		puts("NO");
		return 0;
	}
	puts("YES");
}