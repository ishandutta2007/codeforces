#include <iostream>
#include <iomanip>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
int main() {
	ll n,l,v1,v2,k; cin>>n>>l>>v1>>v2>>k;
	ld imin=0.0,imax=5e18;
	ll num=(n+k-1)/k;
	for (ll k=0;k<350;k++) {
		ld imid=(imin+imax)/2;
		//printf("imin: %f imax: %f imid: %f\n",imin,imax,imid);
		ld t=0.0;
		ld buspos=0.0;
		for (ll i=0;i<num;i++) {
			ld initx=t*v1;
			ld revt=(buspos-initx)/(v1+v2);
			t+=revt;
			initx=t*v1;
			ld tleft=imid-t;
			ld bt=(l-initx-v1*tleft)/(v2-v1);
			t+=bt;
			buspos=initx+bt*v2;
			//printf("t:%f bt: %f buspos: %f\n",t,bt,buspos);
		}
		if (t>imid) imin=imid;
		else imax=imid;
	}
	cout<<fixed<<setprecision(10);
	cout<<imin<<endl;
}