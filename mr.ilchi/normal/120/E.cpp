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

	freopen ("input.txt" , "r" , stdin);
	freopen ("output.txt" , "w" , stdout);

	int t; cin >> t;

	for (int o=1; o<=t; o++){
		
		int n; cin >> n;

		cout << 1-(n%2) << endl;
	}

	return 0;
}