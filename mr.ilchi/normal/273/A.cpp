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
typedef pair<LL,LL> pii;

int n,que;
deque <pii> Q;

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		Q.push_back(pii((LL)temp,1LL));
	}
	cin >> que;
	for (int o=0; o<que; o++){
		int w,h; cin >> w >> h;
		int add = 0;
		LL MAX = 0;
		while (true){
			pii &front = Q.front();
			MAX = max(MAX, front.first);
			if (w > add + front.second){
				add+= front.second;
				Q.pop_front();
			}
			else{
				cout << MAX << endl;
				front.second-= (w-add);
				Q.push_front(pii(MAX + h, w));
				break;
			}
		}
	}
	return 0;
}