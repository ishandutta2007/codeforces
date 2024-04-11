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

int x,n;
int a[1<<20];

int main(){
	cin >> x;
	for (int i=0; i<x; i++) cin >> a[i];
	int temp = x;
	while (temp!=1) temp/=4, n++;
	sort(a, a+x);
	LL ret = 0;
	for (int i=0; i<=n; i++){
		for (int j=0; j<(1<<(2*i)); j++){
			ret+= a[x-1-j];
		}
	}
	cout << ret << endl;
	return 0;
}