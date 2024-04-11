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

int x;

int main(){
	
	cin >> x;

	if (x==3){
		cout << 5 << endl;
		return 0;
	}

	for (int i=1; true; i++){

		if (i%2==0){
			if (x%4==0){
				int cur = i/2 - 1;
				if ((cur * cur + 1) / 2 >= x / 4){
					cout << i << endl;
					return 0;
				}
			}
			continue;
		}
		int cur = i/2;
		int now = (cur * cur + 1) / 2 * 4 + cur/2 * 4 + 1;
		if (x<=now){
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}