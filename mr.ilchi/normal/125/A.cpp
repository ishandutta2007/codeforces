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
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <cstring>
#include <fstream>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef complex<double> point;

int main(){

	int n; cin >> n;

	int a=0,b=0;
	
	while (n>=36) { n-=36; a++; }

	while (n>=3) { n-=3; b++; }

	if (n==2)
		b++;

	while (b>=12) { a++; b-=12; }

	cout << a << ' ' << b << endl;

	return 0;
}