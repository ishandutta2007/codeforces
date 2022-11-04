#include <iostream>

using namespace std;

int main(){
	int n;
	long long tmin, tmax, segmax, imax = 1, a, b;
	cin >> n >> tmin >> tmax;
	segmax = tmax - tmin;

	for(int i = 2; i <= n; i++){
		cin >> a >> b;
		if ( b - a > segmax ){
			segmax = b - a;
			imax = i;
		}
		if ( a < tmin )
			tmin = a;
		if ( b > tmax )
			tmax = b;
	}

	if ( segmax == tmax - tmin )
		cout << imax;
	else
		cout << -1;

	return 0;
}