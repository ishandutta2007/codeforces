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

LL n,m;
string x,y;
int cnt[1<<20][26];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> x >> y;
	int nx = (int)x.size();
	int ny = (int)y.size();
	int d = __gcd(nx,ny);
	for (int i=0; i<(int)y.size(); i++) 
		cnt[i%d][y[i]-'a']++;
	LL ret = 0;
	for (int i=0; i<(int)x.size(); i++)
		ret+= (ny/d - cnt[i%d][x[i]-'a']) * (n / (ny/d)); 
	cout << ret << endl;
	return 0;
}