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

int sum[1<<20];

int main(){
	string s; cin >> s;
	int n = (int)s.size();
	s+= "@";
	for (int i=n-1; i>=0; i--)
		sum[i] = sum[i+1] + (s[i]==s[i+1]);
	int que; cin >> que;
	for (int i=0; i<que; i++){
		int l,r; cin >> l >> r;
		cout << sum[l-1] - sum[r-1] << endl;
	}
	return 0;
}