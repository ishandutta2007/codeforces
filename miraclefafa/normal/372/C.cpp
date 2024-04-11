#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
//#include <iostream>
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
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
const ll mod=1000000007,inf=(1ll<<60);
const double eps=1e-9;
const double pi=acos(0)*2;
ll powmod(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int N=150100;
ll dp[N],pd[N],ans;
int q[N],n,m,d,prt,a[567],b[567],t[567];

void transfer(int leg,int a,int b) {
	int h=1,t=0;
	memset(q,0,sizeof(q));
	rep(i,0,leg) {
		while (h<=t&&dp[i]>dp[q[t]]) --t;
		q[++t]=i;
	}
	rep(i,0,n) {
		if (i+leg<n) {
			while (h<=t&&dp[i+leg]>dp[q[t]]) --t;
			q[++t]=i+leg;
		}
		while (h<=t&&i-q[h]>leg) h++;
		pd[i]=dp[q[h]];
	}
	rep(i,0,n) pd[i]+=b-abs(a-i);
}
int main() {
	scanf("%d%d%d",&n,&m,&d);
	prt=1;
	rep(i,0,m) {
		rep(j,0,n) pd[j]=-inf;
		scanf("%d%d%d",a+i,b+i,t+i);--a[i];
		transfer(min(1ll*(t[i]-prt)*d,1ll*n),a[i],b[i]);
		rep(j,0,n) dp[j]=pd[j];prt=t[i];
	}
	ans=-inf;
	rep(i,0,n) ans=max(ans,pd[i]);
	printf("%I64d\n",ans);
	return 0;
}