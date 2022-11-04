/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

const int maxN= 10000+5;
const double eps= 1e-9;

double n,k;
double a[maxN];

inline void bsearch(){
	double s=a[1], e=a[1];
	for (int i=1;i<=n;i++){
		if (a[i]<s)
			s= a[i];
		if (e<a[i])
			e= a[i];
	}

	e+= 1;

	double res=0;

	for (int i=1;i<=200;i++){
		double mid= (s+e)/2;
		double mosbat=0, manfi=0;
		for (int j=1;j<=n;j++){
			if (a[j]-mid < eps)
				manfi+= (mid-a[j]);
			else
				mosbat+= (a[j]-mid);
		}

		mosbat*= ((100-k)/100);

		if (mosbat-manfi > -eps){
			res= mid; s=mid;
		}
		else
			e=mid;
	}

	cout << fixed << setprecision(8) <<	res << endl;
}
/**********************************/
int main(){
	cin >> n >> k;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	bsearch ();

	return 0;
}