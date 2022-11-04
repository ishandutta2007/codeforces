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

int n,m;
int pos[1<<20];

int main(){
	
	cin >> n >> m;

	if (m%2 == 0){

		int cnt = 0;
		for (int i=m/2; i>0; i--){
			pos[cnt] = i;
			pos[cnt+1] = (m+1)-i;
			cnt+=2;
		}

		for (int i=1; i<=n; i++){
			cout << pos[(i-1)%m] << endl;
		}

		return 0;
	}


	pos[0] = (m+1)/2;

	int cnt = 1;

	for (int i=m/2; i>0; i--){
		pos[cnt] = i;
		pos[cnt+1] = (m+1)-i;
		cnt+=2;
	}

	for (int i=1; i<=n; i++){
		cout << pos[(i-1)%m] << endl;
	}

	return 0;
}