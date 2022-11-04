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
int a[1<<20];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i=1; i<n; i++)
		a[i] = 1;
	a[n] = 0;
	for (int rep=1; rep<=k; rep++){
		for (int i=1; i<=n; i++){
			if (a[i]*2<=n-i){
				cout << i << ' ';
				a[i]<<=1;
			}
			else{
				cout << n-((n-i)-a[i]) << ' ';
				a[i] = n-i;
			}
		}
		cout << endl;
	}
	return 0;
}