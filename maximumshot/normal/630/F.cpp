#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
   vec< vec< ll > > C(1010, vec< ll >(1010));
   
   C[0][0] = 1ll;
   for(int i = 1;i < 1010;i++) {
      C[i][0] = C[i][i] = 1ll;
      for(int j = 1;j < i;j++) {
         C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      }
   }
   
   int n;
   cin >> n;
   
   cout << C[n][5] + C[n][6] + C[n][7] << '\n';
   
 	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}