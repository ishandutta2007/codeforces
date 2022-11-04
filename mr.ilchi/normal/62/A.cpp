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
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int a1, a2, b1, b2;

inline void check (int a, int b){
	if ((a-1)<=b && b<= (2*a+2)){
		cout << "YES" << endl;
		exit(0);
	}
}
/*****************************/
int main(){
	cin >> a1 >> a2 >> b1 >> b2;
	check (a1,b2); 
	check (a2,b1); 
	cout << "NO" << endl;
	return 0;
}