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
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

int main (){
	cin >> n;
	for (int i=2,leni=(int)sqrt((double)n);i<= leni;i ++){
		while (n%i== 0){
			cout << n << ' ';
			n/=i;
		}
	}
	if (n== 1)
		cout << 1 << endl;
	else
		cout << n << ' ' << 1 << endl;
	return 0;
}