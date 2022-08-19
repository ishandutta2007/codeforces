#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <ctime>
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

const double pi=acos(-1.),eps=1e-12;
const int N=201000;
double sqr(double r) { return r*r; }
vector<pair<double,int> > v;
int n,a,x[N],y[N],p[N];
double r1[N],dis[N],ang[N];
set<int> s;
bool check(double R) {
	int cur=0;
	v.clear();
	rep(i,0,n) {
		double p=(R*R+dis[i]*dis[i]-r1[i]*r1[i])/2/R/dis[i];
		if (fabs(p)>1-eps) continue;
		double the=acos(p);
		double l=ang[i]-the,r=ang[i]+the;
		while (l<0) l+=2*pi;
		while (r<0) r+=2*pi;
		v.pb(mp(l,i));
		v.pb(mp(r,i));
	}
	sort(all(v));
	s.clear();
	rep(i,0,n) p[i]=-1;
	rep(i,0,SZ(v)) {
		int id=v[i].se;
		if (p[id]==-1) p[id]=i,s.insert(i);
		else {
			assert(!s.empty());
			if (*(--s.end())!=p[id]) return 1;
			p[id]=-1;
			s.erase(--s.end());
		}
	}
	return 0;
}
int main() {
	scanf("%d%d",&n,&a);
	rep(i,0,n) {
		scanf("%d%d",x+i,y+i);
		r1[i]=sqrt(sqr(x[i]+a)+sqr(y[i]))*0.5;
		dis[i]=sqrt(sqr(x[i]-a)+sqr(y[i]))*0.5;
		ang[i]=atan2(y[i],x[i]-a);
	}
	double l=0,r=a;
	while (clock()<=2.9*CLOCKS_PER_SEC) {
		double md=(l+r)*0.5;
		if (check(md)) r=md; else l=md;
	}
	printf("%.10f\n",2*r);
}