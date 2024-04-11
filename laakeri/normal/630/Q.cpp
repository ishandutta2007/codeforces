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
	ld x1,x2,x3;
	cin>>x1>>x2>>x3;
	cout<<setprecision(15)<<(ld)(1.0/12.0)*sqrt(2)*x1*x1*x1+(ld)(1.0/6.0)*sqrt(2)*x2*x2*x2+(ld)(0.213194697334044)*sqrt(2)*x3*x3*x3<<endl;
}