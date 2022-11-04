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

string s,t;

int main(){
	cin >> s >> t;
	int s1 = count(s.begin(), s.end(), '1');
	int t1 = count(t.begin(), t.end(), '1');
	s1+= (s1%2);
	cout << ((t1<=s1) ? ("YES") : ("NO")) << endl;
	return 0;
}