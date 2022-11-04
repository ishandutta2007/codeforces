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

int main(){
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int R = 0;
	LL ans = 0;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		if (temp == 1)
			R++;
		else
			ans+= R;
	}
	cout << ans << endl;
	return 0;
}