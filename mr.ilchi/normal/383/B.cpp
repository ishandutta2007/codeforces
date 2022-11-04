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

int n,m;
vector <pii> event;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=1; i<=m; i++){
		int x,y; cin >> x >> y;
		event.push_back(pii(y,x));
	}
	sort(event.begin(), event.end());
	int last=0;
	set <pii> SET;
	SET.insert(pii(1,1));
	for (int i=0; i<(int)event.size(); i++){
		int j = i;
		while (j<(int)event.size() && event[i].first == event[j].first)
			j++;
		if (last != event[i].first -1){
			pii temp = *SET.begin();
			SET.clear();
			temp.second = n;
			SET.insert(temp);
		}
		for (int k=i; k<j && !SET.empty(); k++){
			set <pii> :: iterator it = SET.lower_bound(pii(event[k].second+1,-1));
			if (it != SET.begin()) it--;
			if (((it->first)<=event[k].second) && (event[k].second<=(it->second))){
				pii temp = *it;
				SET.erase(temp);
				if (temp.first < event[k].second)
					SET.insert(pii(temp.first, event[k].second-1));
				if (event[k].second < temp.second)
					SET.insert(pii(event[k].second+1, temp.second));
			}
		}
		if (!SET.empty()){
			set <pii> :: iterator it = SET.begin();
			vector <pii> Q;
			for (int k=i; (k<j) && (it!=SET.end()); k++) if (event[k].second > (it->first)){
				int lo = (it->first);
				while ((it!=SET.end()) && ((it->first)<event[k].second))
					it++;
				Q.push_back(pii(lo,event[k].second-1));
			}
			if (it!=SET.end())
				Q.push_back(pii(it->first, n));
			SET.clear();
			for (int k=0; k<(int)Q.size(); k++)
				SET.insert(Q[k]);
		}
		if (SET.empty()){
			cout << -1 << endl;
			return 0;
		}
		last = event[i].first;
		i = j-1;
	}
	if ((last == n) && ((SET.rbegin()->second)!=n))
		cout << -1 << endl;
	else
		cout << 2*n-2 << endl;
	return 0;
}