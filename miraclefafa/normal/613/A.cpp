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

const double pi=acos(-1.);
int n,x[101000],y[101000];
double X,Y;
double ff(int i,double c) {
	double xx=x[i]+c*(x[i+1]-x[i]),yy=y[i]+c*(y[i+1]-y[i]);
	return sqrt((X-xx)*(X-xx)+(Y-yy)*(Y-yy));
}
int main() {
	scanf("%d",&n);
	scanf("%lf%lf",&X,&Y);
	double mx=0;
	rep(i,0,n) {
		scanf("%d%d",x+i,y+i);
		mx=max(mx,sqrt((X-x[i])*(X-x[i])+(Y-y[i])*(Y-y[i])));
	}
	double mn=mx;
	x[n]=x[0]; y[n]=y[0];
	rep(i,0,n) {
		double l=0,r=1;
		rep(j,0,60) {
			double tl=(l+l+r)/3,tr=(l+r+r)/3;
			if (ff(i,tl)<=ff(i,tr)) r=tr; else l=tl;
		}
		mn=min(mn,ff(i,(l+r)/2));
	}
	printf("%.10f\n",pi*(mx*mx-mn*mn));
}