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
const ll mod=1000000007;
const double eps=1e-9;
const double pi=acos(0)*2;
ll powmod(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int n,a[6010000],l,r;
bool check(int x) {
	per(i,0,x) if (i-x+n<x||2*a[i]>a[i-x+n]) return 0;
	return 1;
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	sort(a,a+n);
	l=0;r=n;
	while (l+1<r) {
		int md=(l+r)/2;
		if (check(md)) l=md; else r=md;
	}
	printf("%d\n",n-l);
	return 0;
}