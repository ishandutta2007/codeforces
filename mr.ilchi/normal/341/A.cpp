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

const int MAXN = 100000+10;

int n;
int a[MAXN];
LL sum[MAXN];

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a,a+n);
	for (int i=0; i<n; i++)
		sum[i] = sum[max(0,i-1)] + a[i];
	LL num = sum[n-1], denom = n;
	for (int i=0; i<n; i++){
		num+= (i+1LL) * a[i] - sum[i];
		num+= (sum[n-1]-sum[i]) - (n-i-1LL) * a[i];
	}
	LL d = __gcd(num, denom);
	cout << num/d << ' ' << denom/d << endl;
	return 0;
}