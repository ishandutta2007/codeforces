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

int main(){

	string s; cin >> s;
	string ret = "";

	int past = 0;

	for (char x = 'z'; x>='a'; x--){
		for (int i=past; i<(int)s.size(); i++) if (s[i] == x){
			ret+= x; past = i+1;
		}		
	}

	cout << ret << endl;

	return 0;
}