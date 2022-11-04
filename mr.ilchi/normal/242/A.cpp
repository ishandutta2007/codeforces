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
	
	int x,y,a,b;
	cin >> x >> y >> a >> b;
	vector <pii> ans;
	for (int i=a; i<=x; i++)
		for (int j=b; j<min(i,y+1); j++)
			ans.push_back(pii(i,j));
	cout << ans.size() << endl;
	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;

	return 0;
}