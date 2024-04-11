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

int h,m,s,t1,t2;
bool canwalk(int p,int q,int w) {
	if (q<p) q+=3600*12;
	if (w<p) w+=3600*12;
	return w>q;
}
int main() {
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	h*=3600, m*=3600, s*=3600;
	h=h+m/60+s/3600;
	m=(m+s/60)/5;
	s=s/5;
	h%=3600*12; m%=3600*12; s%=3600*12;
	t1=t1%12*3600,t2=t2%12*3600;
//	printf("%d %d %d %d %d",h,m,s,t1,t2);
	if (canwalk(t1,t2,h)&&canwalk(t1,t2,m)&&canwalk(t1,t2,s)) puts("YES");
	else {
		swap(t1,t2);
		if (canwalk(t1,t2,h)&&canwalk(t1,t2,m)&&canwalk(t1,t2,s)) puts("YES");
		else puts("NO");
	} 
}