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

int n;
int a[1<<20];

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int inv = 0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++) if (a[i]>a[j])
			inv++;
	if (inv == 0){
		cout << 0 << endl;
		return 0;
	}
	inv--;
	cout << 1 + 4 * (inv/2) + (inv%2 == 0 ? 0 : 3) << endl;
	return 0;
}