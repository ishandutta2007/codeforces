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

int a,b,n;

int main(){

	cin >> a >> b >> n;

	int cnt=0;

	while (n!=0){

		if (cnt==0){
			int d = __gcd(a,n);
			n-=d;
		}

		else{
			int d = __gcd(b,n);
			n-=d;
		}

		cnt = 1-cnt;
	}

	cout << 1-cnt << endl;
	
	return 0;
}