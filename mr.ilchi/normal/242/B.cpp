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
int lo[1<<20], hi[1<<20];

int main(){
	cin >> n;
	int mini = (1<<30);
	int maxi = -1;
	for (int i=1; i<=n; i++){
		cin >> lo[i] >> hi[i];
		mini = min(lo[i], mini);
		maxi = max(hi[i], maxi);
	}
	for (int i=1; i<=n; i++) if (lo[i]==mini && maxi==hi[i]){
		cout << i << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}