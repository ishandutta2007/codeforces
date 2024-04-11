#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ld a,b,c;
	cin>>a>>b>>c;
	ld v1=(-b+sqrt(b*b-4*a*c))/(2*a);
	ld v2=(-b-sqrt(b*b-4*a*c))/(2*a);
	cout<<setprecision(15)<<max(v1, v2)<<endl<<min(v1, v2)<<endl;
}