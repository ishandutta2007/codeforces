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
typedef pair<int,int> pii;
typedef complex<double> point;

int a,b;

int main(){
	cin >> a >> b;
	int ans = 0;
	int f0 = a, f1 = 0;
	while (f0!=0 || f1>=b){
		ans+= f0;
		f1 += f0;
		f0 = f1/b;
		f1 %= b;
	}
	cout << ans << endl;
	return 0;
}