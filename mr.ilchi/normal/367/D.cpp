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

int n,m,d;
int sz[20];
int f[1<<20];
vector <int> store[20];

int main(){
	cin >> n >> m >> d;
	for (int i=0; i<m; i++){
		cin >> sz[i];
		for (int j=0; j<sz[i]; j++){
			int temp; cin >> temp;
			temp--;
			store[i].push_back(temp);
		}
		sort(store[i].begin(), store[i].end());
	}
	for (int i=0; i<m; i++){
		for (int j=0; j<(int)store[i].size(); j++){
			int need = (j==(int)store[i].size()-1 || store[i][j]+d<store[i][j+1]) ? (0) : (1<<i);
			for (int k=0; k<m; k++) if (k!=i){
				int poi = lower_bound(store[k].begin(), store[k].end(), store[i][j]) - store[k].begin();
				if (poi != (int)store[k].size() && store[i][j]+d>=store[k][poi])
					need|= (1<<k);
			}
			if (store[i][j] < n-d)
				f[need]|=(1<<i);
		}
	}
	for (int mask=0; mask<(1<<m); mask++)
		for (int i=0; i<m; i++) if (mask & (1<<i))
			f[mask]|= f[mask ^ (1<<i)];
	int ans = m;
	for (int mask = 1; mask < (1<<m); mask++) if ((f[((1<<m)-1) ^ mask] & mask) == 0){
		int mini = n;
		for (int i=0; i<m; i++) if (mask & (1<<i))
			mini = min(mini, store[i][0]);
		if (mini < d)
			ans = min(ans, __builtin_popcount(mask));
	}
	cout << ans << endl;
	return 0;
}