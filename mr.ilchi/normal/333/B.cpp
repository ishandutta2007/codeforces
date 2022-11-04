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

bool row[2000],col[2000];
int n,m;

int main(){
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		x--; y--;
		row[x] = true, col[y] = true;
	}
	int ret = 0;
	for (int i=1; i<(n+1)/2; i++){
		if (n-1-i == i){
			ret+= (row[i]==false || col[i]==false);
		}else{
			int R = int(row[i]==false) + (row[n-1-i]==false);
			int C = int(col[i]==false) + (col[n-1-i]==false);
			ret+= R+C;
		}
	}
	cout << ret << endl;
	return 0;
}