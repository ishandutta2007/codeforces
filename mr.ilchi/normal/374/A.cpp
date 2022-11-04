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

int n,m,i,j,a,b;

void check (int &ans, int x, int y){
	if (x!=-1 && y!=-1 && x%2 == y%2)
		ans = min(ans, max(x,y));
}

int main(){
	cin >> n >> m >> i >> j >> a >> b;
	i--; j--;
	int up = (i%a != 0) ? (-1) : (i/a);
	int bot= (i%a != (n-1)%a) ? (-1) : ((n-1-i)/a);
	int lef= (j%b != 0) ? (-1) : (j/b);
	int rig= (j%b != (m-1)%b) ? (-1) : ((m-1-j)/b);
	int ans = 1000000000;
	check(ans, lef, up);
	check(ans, lef, bot);
	check(ans, rig, up);
	check(ans, rig, bot);
	if (ans == 1000000000 || (ans!=0 && (n<=a || m<=b)))
		cout <<  "Poor Inna and pony!" << endl;
	else
		cout << ans << endl;
	return 0;
}