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

#define ff first
#define ss second

using namespace std;

typedef long long LL;
typedef long long ll;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<int,int> pie;

int n,d;
int x[1<<20];

int main(){
	cin >> n >> d;
	for (int i=0; i<n; i++)
		cin >> x[i];
	LL ans = 0;
	for (int i=0; i<n; i++){
		int cnt = upper_bound(x+i+1,x+n,x[i]+d) - x - i - 1;
		ans+= (LL)cnt * (cnt-1) / 2;
	}
	cout << ans << endl;
	return 0;
}