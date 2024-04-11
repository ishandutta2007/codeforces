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

bool lamp[1<<20];
int n,que;
int func[1<<20],a[1<<20],b[1<<20];

inline void go (int root, int lo, int hi, int x, int y, int k){
	if ((hi<y) || (y+k-1<lo))
		return;
	if ((y<=lo) && (hi<=y+k-1)){
		lamp[root] = true;
		func[root] = x + (lo-y);
		return;
	}
	int mid = (lo+hi)/2;
	if (lamp[root]){
		lamp[root] = false;
		lamp[root<<1] = lamp[(root<<1)+1] = true;
		func[root<<1] = func[root];
		func[(root<<1)+1] = func[root] + (mid+1-lo);
		if (func[root]==-1)
			func[(root<<1)+1] = -1;
	}
	go((root<<1), lo, mid, x, y, k);
	go((root<<1)+1, mid+1, hi, x, y, k);
}

inline int get (int root, int lo, int hi, int pos){
	if (lamp[root]){
		if (func[root]==-1)
			return b[pos];
		return a[func[root]+(pos-lo)];
	}
	int mid = (lo+hi)/2;
	if (pos<=mid)
		return get(root<<1, lo, mid, pos);
	else
		return get((root<<1)+1, mid+1, hi, pos);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> que;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	lamp[1] = true;
	func[1] = -1;
	for (int o=0; o<que; o++){
		int ord; cin >> ord;
		if (ord==1){
			int x,y,k; cin >> x >> y >> k;
			x--; y--;
			go(1, 0, n-1, x, y, k);
		}else{
			int p; cin >> p; p--;
			cout << get(1, 0, n-1, p) << endl;
		}
	}
	return 0;
}