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

#define plus adfasdfsa
#define minus asdfasfda
char op,s[10];
int plus,minus,n,m,np[110],nm[110],cr[110];
int main() {
	op='+';
	while (1) {
		if (op=='+') plus++,cr[m]=0;
		else minus++,cr[m]=1;
		m++;
		scanf("%s",s);
		scanf("%s",s);
		op=s[0];
		if (op=='=') break;
	}
//	printf("%d %d\n",plus,minus);
	scanf("%d",&n);
	if (plus-minus*n>n||plus*n-minus<n) {
		puts("Impossible");
		return 0;
	}
	puts("Possible");
	rep(i,0,plus) np[i]=1;
	rep(i,0,minus) nm[i]=n;
	int c=n-(plus-minus*n);
	rep(i,0,plus) {
		int delta=min(c,n-np[i]);
		np[i]+=delta; c-=delta;
	}
	rep(i,0,minus) {
		int delta=min(c,nm[i]-1);
		nm[i]-=delta; c-=delta;
	}
	int vp=0,vm=0;
	rep(i,0,m) {
		if (cr[i]==0) printf("%d ",np[vp++]);
		else printf("%d ",nm[vm++]);
		if (i==m-1) printf("= ");
		else if (cr[i+1]==0) printf("+ ");
		else printf("- ");
	}
	printf("%d\n",n);
}