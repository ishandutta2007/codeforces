#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

int k,x,n,m;
ll check(int s1c,int s1a,ll s1ac,int s2c,int s2a,ll s2ac) {
	if (k==1) return s1ac;
	if (k==2) return s2ac;
	ll s3c,s3a,s3ac;
	rep(i,3,k+1) {
		s3c=s1c;s3a=s2a;
		s3ac=s1ac+s2ac+(s1a&&s2c);
		s1c=s2c;s1a=s2a;s1ac=s2ac;
		s2c=s3c;s2a=s3a;s2ac=s3ac;
	}
	return s3ac;
}
int main() {
	scanf("%d%d%d%d",&k,&x,&n,&m);
	rep(s1c,0,2) rep(s1a,0,2) for (int s1ac=0;s1ac*2+s1c+s1a<=n;s1ac++) 
	rep(s2c,0,2) rep(s2a,0,2) for (int s2ac=0;s2ac*2+s2c+s2a<=m;s2ac++)
	if (check(s1c,s1a,s1ac,s2c,s2a,s2ac)==x) {
		if (s1c) putchar('C');
		rep(i,0,s1ac) printf("AC");
		for (int i=s1c+2*s1ac;i+s1a<n;i++) printf("B");
		if (s1a) printf("A");
		puts("");
		if (s2c) putchar('C');
		rep(i,0,s2ac) printf("AC");
		for (int i=s2c+2*s2ac;i+s2a<m;i++) printf("B");
		if (s2a) printf("A");
		return 0;
	}
	puts("Happy new year!");
}