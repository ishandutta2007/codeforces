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

int n;

int main(){
	
	cin >> n;

	int res=1;
	
	while (res * (res-1) / 2 <= n) res++; res--;

	vector <int> Q[res+10];

	int cnt = 1;

	for (int i=1; i<=res; i++){
		for (int j=i+1; j<=res; j++){
			Q[i].push_back (cnt);
			Q[j].push_back (cnt); cnt++;
		}
	}

	cout << res << endl;

	for (int i=1; i<=res; i++){
		for (int j=0; j<(int)Q[i].size(); j++)
			cout << Q[i][j] << ' ';
		cout << endl;
	}

	return 0;
}