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
int p[1<<20];

int main(){
	cin >> n;
	if (n%4 > 1){
		cout << -1 << endl;
		return 0;
	}
	for (int i=1; i<=n/2; i+=2){
		p[i] = i+1;
		p[i+1]=n-i+1;
		p[n-i]=i;
		p[n-i+1]=n-i;
	}
	if (n%4==1)
		p[(n+1)/2] = (n+1)/2;
	for (int i=1; i<=n; i++)
		cout << p[i] << ' ';
	return 0;
}