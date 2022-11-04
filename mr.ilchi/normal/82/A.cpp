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
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

int n;
string name[]= {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main(){
	cin >> n;

	int less=5;

	while (n>less){
		n-= less;
		less*=2;
	}

	less/=5;

	for (int i=1;i<=5;i++) if (n<=i*less){
		cout << name[i-1] << endl;
		return 0;
	}

	return 0;
}