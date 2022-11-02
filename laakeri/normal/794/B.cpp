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
	int n;
	ld h;
	cin>>n>>h;
	ld area=h/(ld)2;
	area/=(ld)n;
	cout<<setprecision(15);
	for (int i=1;i<n;i++){
		ld ta=area*(ld)i;
		ld mi=0;
		ld ma=h;
		for (int j=0;j<200;j++){
			ld mid=(mi+ma)/2;
			ld ba=(mid/h);
			ld aa=ba*mid/(ld)2;
			if (aa>ta){
				ma=mid;
			}
			else{
				mi=mid;
			}
		}
		cout<<mi<<" ";
	}
	cout<<endl;
}