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
	stack <char> Q;
	Q.push('+');
	for (int i=0; i<(int)s.size(); i++){
		if (Q.empty())
			Q.push(s[i]);
		else if (Q.top()==s[i])
			Q.pop();
		else
			Q.push(s[i]);
	}
	if ((int)Q.size()==1 && Q.top() == '+')
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}