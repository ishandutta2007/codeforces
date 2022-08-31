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
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
char s[N];
int m,v[30],n;

int gao(int c) {
	int pre=-1,cand=-1,ret=0;
	rep(i,0,n) {
		if (s[i]<'a'+c) pre=i,cand=i;
		if (s[i]=='a'+c) cand=i;
		if (i-pre==m) {
			if (cand>pre) {
				ret++; pre=cand;
			} else return -1;
		}
	}
	return ret;
}
int main() {
	scanf("%d",&m);
	scanf("%s",s);
	n=strlen(s);
	rep(i,0,n) v[s[i]-'a']++;
	rep(i,0,26) {
		int c=gao(i);
		if (c!=-1) {
			rep(j,0,i) rep(k,0,v[j]) putchar('a'+j);
			rep(k,0,c) putchar('a'+i);
			puts("");
			return 0;
		}
	}
	assert(0);
}