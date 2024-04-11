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
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int a,b,c;

inline int no0 (int v){
	int ret=0, pow=1;

	while (v){
		int mod = v%10;

		if (mod!=0){
			ret= ret + pow*mod;
			pow*=10;
		}

		v/=10;
	}

	return ret;
}
/********************************/
int main(){
	cin >> a >> b; c=a+b;

	a= no0(a);
	b= no0(b);
	c= no0(c);

	if (a+b==c)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}