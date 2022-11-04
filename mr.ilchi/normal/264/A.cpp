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

const int MAXN = 1000 * 1000+10;

string s;
int a[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s;
	int head = 0, tail = (int)s.size()-1;
	for (int i=0; i<(int)s.size(); i++){
		if (s[i] == 'l')
			a[tail--] = i + 1;
		else
			a[head++] = i + 1;
	}
	for (int i=0; i<(int)s.size(); i++)
		cout << a[i] << endl;
	return 0;
}