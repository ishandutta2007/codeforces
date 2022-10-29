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
using namespace std;
typedef long long ll;

ll ax,ay,bx,by,cx,cy;

int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&ax,&ay,&bx,&by,&cx,&cy);
	ll d0x=ax-bx,d0y=ay-by,d1x=ax-cx,d1y=ay-cy;
	if(d0x*d1y==d1x*d0y)puts("No");
	else {
		d1x=bx-cx,d1y=by-cy;
		if(d0x*d0x+d0y*d0y==d1x*d1x+d1y*d1y)puts("Yes");
		else puts("No");
	}
	return 0;
}