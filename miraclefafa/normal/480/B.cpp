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

int n,l,x,y;
const int N=101000;
int p[N];
set<int> st;
bool c1=0,c2=0;
bool check0() {
	rep(i,0,n) {
		if (st.count(p[i]+x)||st.count(p[i]-x)) c1=1;
		if (st.count(p[i]+y)||st.count(p[i]-y)) c2=1;
	}
	return c1&&c2;
}
bool check(int c) {
	if (st.count(c)||c<0||c>l) return 0;
	if ((c1||st.count(c+x)||st.count(c-x))&&(c2||st.count(c+y)||st.count(c-y))) {
		puts("1");
		printf("%d\n",c);
		return 1;
	}
	return 0;
}
int main() {
	scanf("%d%d%d%d",&n,&l,&x,&y);
	rep(i,0,n) {
		scanf("%d",p+i);
		st.insert(p[i]);
	}
	if (check0()) {
		puts("0");
		return 0;
	}
	rep(i,0,n) if (check(p[i]+x)||check(p[i]-x)||check(p[i]+y)||check(p[i]-y)) {
		return 0;
	}
	puts("2");
	printf("%d %d\n",x,y);
}