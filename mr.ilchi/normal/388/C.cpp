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
	int n; cin >> n;
	int a = 0, b = 0;
	vector <int> Q;
	for (int i=0; i<n; i++){
		int len; cin >> len;
		for (int i=0; i<len; i++){
			int temp; cin >> temp;
			if (i<len/2) 
				a+= temp;
			else if (i>=(len+1)/2)
				b+= temp;
			else
				Q.push_back(temp);
		}
	}
	sort(Q.rbegin(), Q.rend());
	for (int i=0; i<(int)Q.size(); i++){
		if (i%2 == 0)
			a+= Q[i];
		else
			b+= Q[i];
	}
	cout << a << ' ' << b << endl;
	return 0;
}