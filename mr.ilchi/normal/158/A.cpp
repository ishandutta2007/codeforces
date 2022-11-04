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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int n,k;
int a[100];

int main(){
	cin >> n >> k;
	int ans = 0;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		if (a[i]>0 && a[i]>=a[k])
			ans=i;
	}
	cout << ans << endl;
	return 0;
}