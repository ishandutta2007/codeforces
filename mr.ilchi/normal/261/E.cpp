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

const int inf = 1000000000;

int lo,hi,move,ret;
vector <int> prime,comp;
vector <pii> Q;

inline void go (int cur, int pos){
	Q.push_back(pii(cur,prime[pos]));
	for (int i=pos; i<(int)prime.size(); i++) if ((LL)cur * prime[i] <= hi)
		go(cur * prime[i], i);
}

int main(){
	cin >> lo >> hi >> move;
	for (int i=2; i<move; i++){
		bool f = false;
		for (int j=2; j<i; j++) if (i%j == 0)
			f = true;
		if (!f)
			prime.push_back(i);
	}
	if (!prime.empty())
		go(1,0);
	sort(Q.begin(),Q.end());
	vector <int> dp ((int)Q.size()+10,inf);
	vector <int> ans((int)Q.size()+10,inf);
	dp[0] = ans[0] = 0;
	for (int i=2; i<move; i++){
		int poi = 0;
		int step = max(5, i);
		for (int j=0; j<(int)Q.size(); j++) if (Q[j].second<=i && Q[j].first %i == 0){
			int temp = Q[j].first/i;
			while (Q[poi].first <temp) poi=min(j-1,poi+step);
			while (Q[poi].first >temp) poi--;
			dp [j] = min(dp [j], dp[poi]+1);
			ans[j] = min(ans[j], dp[j] + i);
		}
	}
	int ret = 0;
	for (int i=0; i<(int)Q.size(); i++) if (Q[i].first>=lo && ans[i]<=move)
		ret++;
	cout << ret << endl;
	return 0;
}