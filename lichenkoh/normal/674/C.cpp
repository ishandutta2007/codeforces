#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=200000+4;
const ll MAXK=50+2;
ld t[MAXN];
ld sinv[MAXN];
ld ss[MAXN];
ld f[MAXK][MAXN];

ld A[MAXN],B[MAXN];
ll len;
ll ptr;
// a decreasing
void addLine(ld a, ld b) {
	//printf("Addline: %f %f\n",a,b);
  // intersection of (A[len-2],B[len-2]) with (A[len-1],B[len-1]) must lie to the right of intersection of (A[len-1],B[len-1]) with (a,b)
  while (len >= 2 && (B[len - 2] - B[len - 1]) * (a - A[len - 1]) <= (B[len - 1] - b) * (A[len - 1] - A[len - 2])) {
    --len;
  }
  A[len] = a;
  B[len] = b;
  ++len;
}
// x decreasing
ld maxValue(ld x) {
  ptr = min(ptr, len - 1);
  while (ptr + 1 < len && A[ptr + 1] * x + B[ptr + 1] >= A[ptr] * x + B[ptr]) {
    ++ptr;
  }
  ld ans= A[ptr] * x + B[ptr];
  //printf("maxValue %f is %f\n",x,ans);
  return ans;
}

int main() {
	ll n,klim;
	scanf("%d %d",&n,&klim);
	for (ll x=1;x<=n;x++) {
		ll tmp;
		scanf("%d",&tmp);
		t[x]=tmp;
	}
	sinv[0]=0;
	for (ll x=1;x<=n;x++) sinv[x]=sinv[x-1]+(1.0/t[x]);
	ss[0]=0;
	for (ll x=1;x<=n;x++) ss[x]=ss[x-1]+t[x];
	ld total=0;
	for (ll x=1;x<=n;x++) {
		total+=(t[x]*(sinv[n]-sinv[x-1]));
	}
	for (ll k=0;k<=klim;k++) for (ll x=0;x<=n;x++) f[k][x]=0;
	for (ll k=0;k<klim;k++) {
		len=0,ptr=0;

		for (ll x=0;x<=n;x++) {
			if(x>0) {
				ld z=sinv[n]-sinv[x];
				ld ans=maxValue(z)+(ss[x]-ss[n])*z;
				f[k+1][x]=ans;
			}
			addLine((ss[n]-ss[x]), (f[k][x]));
		}

		for (ll x=0;x<=n;x++) {
			//printf("%d %d: %f\n",k+1,x,f[k+1][x]);
		}
	}
	ld ans=total-f[klim][n];
	std::cout << std::fixed;
	cout.precision(10);
	cout<<ans<<endl;
}