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

int n,neg;
int a[1<<20];

int main(){
	cin >> n;
	for (int i=0; i<2*n-1; i++){
		cin >> a[i];
		if (a[i]<0) neg++;
		a[i] = max(a[i], -a[i]);
	}
	sort(a, a+2*n-1);
	int sum = 0;
	for (int i=0; i<2*n-1; i++)
		sum+= a[i];
	if (neg%2!=0 && n%2==0)
		sum-=a[0] * 2;
	cout << sum << endl;
	return 0;
}