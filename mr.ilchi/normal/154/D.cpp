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

int x1,x2,a,b;

int main(){
	
	cin >> x1 >> x2 >> a >> b;

	bool sw = false;

	if (x1 > x2){
		swap(x1,x2);
		a=-a; b=-b;
		swap(a,b);
		sw = true;
	}

	if (a<=0 && 0<=b){	
		if (x2 - x1 <= b){
			cout << "FIRST" << endl;
			if (sw)
				cout << x1 << endl;
			else
				cout << x2 << endl; 
		}
		else
			cout << "DRAW" << endl;
		return 0;
	}

	if (b<0){
		cout << "DRAW" << endl;
		return 0;
	}

	int dis = (x2 - x1) % (a+b);

	if (dis == 0){
		cout << "SECOND" << endl;
		return 0;
	}

	if (dis<=a-1 || dis>b){
		cout << "DRAW" << endl;
		return 0;
	}

	cout << "FIRST" << endl;

	if (!sw)
		cout << x1 + dis << endl; 
	else
		cout << x2 - dis << endl;

	return 0;
}