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

const int maxN = 1000 + 5;

bool mark[maxN];
int n,k;

int main(){
	
	freopen ("input.txt" , "r" , stdin);
	freopen ("output.txt" , "w" , stdout);

	cin >> n >> k; k--;

	for (int i=0; i<n; i++)
		cin >> mark[i];

	while (!mark[k]) k = (k+1)%n;

	cout << k+1 << endl;

	return 0;
}