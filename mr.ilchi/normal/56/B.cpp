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
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAXN= 1000+5;

int n;
int p[MAXN];

int main (){
	cin >> n;
	for (int i= 1;i<= n;i ++)
		cin >> p[i];
	int e= -1;
	for (int i= n;i>= 1;i --){
		if (p[i] > i){
			cout << "0 0" << endl;
			return 0;
		}
		if (p[i] < i){
			e= i;
			break;
		}
	}
	if (e== -1){
		cout << "0 0" << endl;
		return 0;
	}
	int s= -1;
	for (int i= 1;i< e;i ++){
		if (p[i] < i){
			cout << "0 0" << endl;
			return 0;
		}
		if (p[i] > i){
			s= i;
			break;
		}
	}
	reverse (p+s, p+e+1);
	for (int i= 1;i<= n;i ++)
		if (i!= p[i]){
			cout << "0 0" << endl;
			return 0;
		}
	cout << s << ' ' << e << endl;
	
	return 0;
}