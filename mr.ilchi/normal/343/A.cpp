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

LL a,b;

inline LL go(LL a, LL b){
	if (a == 0)
		return 0LL;
	if (a >= b)
		return a/b + go(a%b, b);
	return 1 + go(b-a, a);
}

int main(){
	cin >> a >> b;
	cout << go(a,b) << endl;
	return 0;
}