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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout<<setprecision(15);
	ld px,py,vx,vy,a,b,c,d;
	cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
	co p(px, py);
	co v(vx, vy);
	v/=abs(v);
	
	co p1=p+v*b;
	cout<<p1.X<<" "<<p1.Y<<endl;
	co p2=p+v*polar((ld)1, PI/(ld)2)*(a/2);
	cout<<p2.X<<" "<<p2.Y<<endl;
	co p3=p+v*polar((ld)1, PI/(ld)2)*(c/2);
	cout<<p3.X<<" "<<p3.Y<<endl;
	co p4=p+v*(-d)+v*polar((ld)1, PI/(ld)2)*(c/2);
	cout<<p4.X<<" "<<p4.Y<<endl;
	co p5=p+v*(-d)+v*polar((ld)1, -PI/(ld)2)*(c/2);
	cout<<p5.X<<" "<<p5.Y<<endl;
	co p6=p+v*polar((ld)1, -PI/(ld)2)*(c/2);
	cout<<p6.X<<" "<<p6.Y<<endl;
	co p7=p+v*polar((ld)1, -PI/(ld)2)*(a/2);
	cout<<p7.X<<" "<<p7.Y<<endl;
}