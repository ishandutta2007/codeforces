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

typedef long long ll;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 100*1000+10;
const int MAXT = (1<<18)+10;

int n,que;
int v[MAXN],c[MAXN];
ll dpA[MAXN], dpB[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> que;
	for (int i=0; i<n; i++)
		cin >> v[i];
	for (int i=0; i<n; i++){
		cin >> c[i];
		c[i]--;
	}
	for (int o=0; o<que; o++){
		int a,b; cin >> a >> b;
		memset(dpA, 0, sizeof dpA);
		memset(dpB, 0, sizeof dpB);
		int min1 = n;
		int min2 = n;
		for (int i=n-1; i>=0; i--){
			ll tmp = (min1 != c[i]) ? (dpB[min1]) : (dpB[min2]);
			dpB[c[i]] = max(dpB[c[i]], (ll)b*v[i] + max(tmp, dpA[c[i]]));
			dpA[c[i]] = max(dpA[c[i]], (ll)a*v[i] + max(tmp, dpA[c[i]]));
			if (min1 == c[i]) 
				continue;
			if (c[i] == min2){
				if (dpB[min2] > dpB[min1])
					swap(min1,min2);
				continue;
			}
			if (dpB[min1] < dpB[c[i]]){
				min2 = min1;
				min1 = c[i];
			}else if (dpB[min2] < dpB[c[i]]){
				min2 = c[i];
			}
		}
		cout << (*max_element(dpB, dpB+n)) << endl;
	}
	return 0;
}