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

int main(){
	string s; cin >> s;
	int x; cin >> x;
	for (int i=0; i<(int)s.size(); i++)
		s[i] = tolower(s[i]);
	for (int i=0; i<(int)s.size(); i++) if (s[i]<x+97)
		s[i] = toupper(s[i]);
	cout << s << endl;
	return 0;
}