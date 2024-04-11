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
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll ,ll > pll;
typedef complex<double> point;

int n,m;

int main(){

	cin >> n >> m;

	if (n>m)
		swap (n,m);

	if (n==1){
		cout << m << endl;
		return 0;
	}

	if (n==2){

		int k = m/4;

		if (m%4==0)
			k--;

		if (m%4==1)
			cout << 4*k + 2 << endl;
		else
			cout << 4*k + 4 << endl;

		return 0;
	}

	int p = (m * n + 1)/2;

	cout << max (p , max (n * ((m+2)/3) , m * ((n+2)/3))) << endl;
	
	return 0;
}