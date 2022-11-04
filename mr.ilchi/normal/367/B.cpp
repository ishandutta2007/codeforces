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

int n,m,p;
int a[1<<20],b[1<<20];
vector <int> Q[1<<20];
map <int,int> mp;
vector <int> ans;

void go (vector <int> Q, int index){
	if ((int)Q.size() < m)
		return;
	map <int,int> X = mp;
	int notzero= (int)mp.size();
	for (int i=0; i<(int)Q.size(); i++){
		X[Q[i]]--;
		int f0 = X[Q[i]];
		if (f0 == 0)
			notzero--;
		if (f0 == -1)
			notzero++;
		if (i>=m){
			X[Q[i-m]]++;
			f0 = X[Q[i-m]];
			if (f0 == 0)
				notzero--;
			else if (f0 == 1)
				notzero++;
		}
		if (notzero==0)
			ans.push_back((i-m+1) * p + index + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> p;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<m; i++) cin >> b[i];
	for (int i=0; i<m; i++)
		mp[b[i]]++;
	for (int i=0; i<n; i++)
		Q[i%p].push_back(a[i]);
	for (int i=0; i<p; i++)
		go(Q[i], i);
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i] << ' ';
	if (!ans.empty())
		cout << endl;
	return 0;
}