#include <iostream>
#include <iomanip>
#include <cmath>
#define ll long long

using namespace std;

int main(){
	int n, m;
	ll a, b, nmax, nmin, mmax, mmin;

	cin >> n >> nmax >> nmin;
	while (--n){
		cin >> a >> b;
		if (b < nmin)
			nmin = b;
		if (a > nmax)
			nmax = a;
	}

	cin >> m >> mmax >> mmin;
	while (--m){
		cin >> a >> b;
		if (b < mmin)
			mmin = b;
		if (a > mmax)
			mmax = a;
	}

	ll dif1 = mmax - nmin;
	ll dif2 = nmax - mmin;
	if ( max(dif1, dif2) <= 0 )
		cout << 0;
	else
		cout << max(dif1, dif2);

	return 0;
}