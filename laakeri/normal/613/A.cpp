#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> co;
const ld PI=atan2(0, -1);

ld pointSegmentDistance(co p, co a, co b) {
	co z=(p-a)/(b-a);
	if(z.X<0) return abs(p-a);
	if(z.X>1) return abs(p-b);
	return abs(z.Y)*abs(b-a);
}

co a[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ld xx,yy;
	cin>>n>>xx>>yy;
	ld mi=1e18;
	ld ma=0;
	for (int i=0;i<n;i++){
		ld x,y;
		cin>>x>>y;
		x-=xx;
		y-=yy;
		a[i]={x, y};
	}
	if (n>1){
		for (int i=0;i<n;i++){
			ld d=pointSegmentDistance({0, 0}, a[i], a[(i+1)%n]);
 			//cout<<d<<endl;
			mi=min(mi, d);
			ma=max(ma, d);
			ma=max(ma, abs(a[i]));
		}
	}
	cout<<setprecision(15)<<PI*ma*ma-PI*mi*mi<<endl;
}