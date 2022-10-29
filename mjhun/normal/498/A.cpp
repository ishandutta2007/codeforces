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
#define SZ(x) ((int)x.size())
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

int sgn(ll t){return t>0?1:-1;}

int main(){
	ll x1,y1,x2,y2;int n,r=0;
	scanf("%lld%lld%lld%lld%d",&x1,&y1,&x2,&y2,&n);
	fore(_,0,n){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(sgn(a*x1+b*y1+c)!=sgn(a*x2+b*y2+c))r++;
	}
	printf("%d\n",r);
	return 0;
}