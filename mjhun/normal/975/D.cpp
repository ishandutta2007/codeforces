#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n;ll a,b,r;
ll x[200005],vx[200005],vy[200005];
map<ll,int> q0;map<pair<ll,ll>,int> q1;

int main(){
	scanf("%d%lld%lld",&n,&a,&b);
	fore(i,0,n)scanf("%lld%lld%lld",x+i,vx+i,vy+i),q0[a*vx[i]-vy[i]]++,q1[mp(a*vx[i]-vy[i],vx[i])]++;
	fore(i,0,n)r+=q0[a*vx[i]-vy[i]]-q1[mp(a*vx[i]-vy[i],vx[i])];
	printf("%lld\n",r);
	return 0;
}