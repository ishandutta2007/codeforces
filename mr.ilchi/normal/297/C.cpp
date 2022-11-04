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
int b[1<<20],c[1<<20];
pii a[1<<20];

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a+n);
	cout << "YES" << endl;
	int len = n/3;
	int cur = n-len;
	for (int i=len; i>0; i--)
		b[a[cur++].second] = i;
	for (int i=n-2*len; i<n-len; i++)
		b[a[i].second] = a[i].first;
	for (int i=0; i<n; i++) swap(a[i].first, a[i].second);
	sort(a,a+n);
	for (int i=0; i<n; i++)
		cout << b[i] << ' ';
	cout << endl;
	for (int i=0; i<n; i++)
		cout << a[i].second-b[i] << ' ';
	cout << endl;
	return 0;
}