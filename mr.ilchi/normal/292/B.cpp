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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

int n,e;
int d[1<<20];

int main(){
	cin >> n >> e;
	if (e > n){
		cout << "unknown topology" << endl;
		return 0;
	}
	for (int i=0; i<e; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		d[e1]++;
		d[e2]++;
	}
	if (e==n){
		if (count(d, d+n, 2) != n)
			cout << "unknown topology" << endl;
		else
			cout << "ring topology" << endl;
		return 0;
	}
	if ((*max_element(d, d+n))==(n-1)){
		cout << "star topology" << endl;
		return 0;
	}
	if ((*max_element(d,d+n))==2){
		cout << "bus topology" << endl;
		return 0;
	}
	cout << "unknown topology" << endl;
	return 0;
}