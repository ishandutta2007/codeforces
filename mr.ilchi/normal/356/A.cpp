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

int ans[1<<20];

int main(){
	ios_base::sync_with_stdio(false);
	int n,m; cin >> n >> m;
	set <int> SET;
	for (int i=0; i<n; i++)
		SET.insert(i);
	for (int i=0; i<m; i++){
		int L,R,winner; cin >> L >> R >> winner;
		L--; R--; winner--;	
		set <int> :: iterator it = SET.lower_bound(L);
		vector <int> Q;
		while ((it!=SET.end()) && ((*it)<=R)){
			if ((*it)!=winner)
				Q.push_back(*it);
			it++;
		}
		for (int i=0; i<(int)Q.size(); i++){
			ans[Q[i]] = winner+1;
			SET.erase(Q[i]);
		}
	}
	for (int i=0; i<n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}