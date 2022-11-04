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
 */

#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

typedef long double ldb;

int up, down, k;

int main(){
	cin >> up >> down >> k;
	if (up+k < down){
		cout << "0.0000" << endl;
		return 0;
	}

	if (k >= down){
		cout << "1.0000" << endl;
		return 0;
	}

	ldb ans=1;
	for (int i=0, so=down, de=up+k+1; i<=k ; i++, so--, de--)
		ans*= (ldb)so/(ldb)de;

	ans= 1-ans;

	cout << fixed << setprecision(5) << ans << endl;
		
	return 0;	
}