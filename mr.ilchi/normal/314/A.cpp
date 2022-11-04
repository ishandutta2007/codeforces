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

int n,k;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	LL cur = 0, pos = 1;
	for (int i=1; i<=n; i++){
		LL a; cin >> a;
		LL N = (n-i) + pos;
		LL temp = cur - a * (N-pos) * (pos-1LL);
		if (temp < k)
			cout << i << endl;
		else{
			cur+= (pos-1) * a;
			pos++;
		}
	}
	return 0;
}