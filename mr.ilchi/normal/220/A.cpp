/*
 * in the name of god
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
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100000+10;

int n;
int a[MAXN],b[MAXN];

int main(){
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	int d=0;
	for (int i=1; i<=n; i++) if (a[i]!=b[i])
		d++;
	if (d<=2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}