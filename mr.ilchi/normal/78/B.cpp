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
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const string col= "ROYGBIV";

int n;
string res;

int main(){

	cin >> n;

	for (int i=1;i<=n-3;i++)
		res+= col[(i-1)%4];

	res+= col[4];
	res+= col[5];
	res+= col[6];

	cout << res << endl;

	return 0;
}