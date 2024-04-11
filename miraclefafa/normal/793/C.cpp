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

#define y1 ljfklasdjfdsklfjs
int n,x1,y1,x2,y2,rx,ry,vx,vy;
PII mx,mn;
int cmpp(PII a,PII b) {
	ll s=(ll)a.fi*b.se-(ll)a.se*b.fi;
	if (s<0) return -1;
	else if (s==0) return 0; else return 1;
}
PII maxx(PII a,PII b) {
	if (cmpp(a,b)>=0) return a; else return b;
}
PII minn(PII a,PII b) {
	if (cmpp(a,b)<=0) return a; else return b;
}
int main() {
	scanf("%d",&n);
	mn=mp(0,1); mx=mp(1000000,1);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	rep(i,0,n) {
		scanf("%d%d%d%d",&rx,&ry,&vx,&vy);
		if (vx==0) {
			if (rx<=x1||rx>=x2) {
				puts("-1"); return 0;
			}
		} else {
			if (vx>0) {
				mn=maxx(mn,mp(x1-rx,vx));
				mx=minn(mx,mp(x2-rx,vx));
			} else {
				mn=maxx(mn,mp(rx-x2,-vx));
				mx=minn(mx,mp(rx-x1,-vx));
			}
		}
		if (vy==0) {
			if (ry<=y1||ry>=y2) {
				puts("-1"); return 0;
			}
		} else {
			if (vy>0) {
				mn=maxx(mn,mp(y1-ry,vy));
				mx=minn(mx,mp(y2-ry,vy));
			} else {
				mn=maxx(mn,mp(ry-y2,-vy));
				mx=minn(mx,mp(ry-y1,-vy));
			}
		}
	}
	if (cmpp(mn,mx)>=0)  puts("-1");
	else printf("%.10f\n",1.*mn.fi/mn.se);
}