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
	cin >> n >> k;
	if (n < k){
		cout << -1 << endl;
		return 0;
	}
	if (k==1){
		if (n==1)
			cout << 'a' << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	string ret = "";
	for (int i=0; i<(n-(k-2))/2; i++)
		ret+= "ab";
	if ((int)ret.size() + k-2 < n)
		ret+="a";
	for (int i=2; i<k; i++)
		ret+= char('a' + i);
	cout << ret << endl;
	return 0;
}