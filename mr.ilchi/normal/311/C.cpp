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
#include <cassert>
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

const int MAXK = 10000+10;
const int MAXN = 100000+10;
const LL inf = (1LL<<60);

int n,m,k;
int c[MAXN];
LL dis[MAXK],a[MAXN];
vector <int> Q[MAXK];

struct cmp{
	inline bool operator () (const int &A, const int &B){
		return dis[A]<dis[B];
	}
};

inline bool cmp2 (const int &A, const int &B){
	return a[A]<a[B];
}

int main(){
	LL h; cin >> h;
	cin >> n >> m >> k;
	for (int i=0; i<n; i++){
		cin >> a[i] >> c[i]; a[i]--;
		Q[a[i]%k].push_back(i);
	}
	for (int i=0; i<k; i++)
		dis[i] = inf;
	dis[0] = 0;
	for (int i=0; i<k; i++)
		sort(Q[i].begin(), Q[i].end(), cmp2);
	set <pii> SET;
	for (int i=0; i<(int)Q[0].size(); i++)
		SET.insert(pii(c[Q[0][i]], -Q[0][i]));
	Q[0].clear();
	for (int i=0; i<m; i++){
		int type; cin >> type;
		if (type == 1){
			LL len; cin >> len;
			set <int, cmp> SET2;
			for (int j=0; j<k; j++) if (dis[j]!=inf)
				SET2.insert(j);
			while (!SET2.empty()){
				int begin = *SET2.begin(); SET2.erase(SET2.begin());
				LL next = dis[begin] + len;
				if (next < dis[next%k]){
					SET2.erase(next%k);
					dis[next%k] = next;
					SET2.insert(next%k);
				}
			}
			for (int j=0; j<k; j++){
				while (!Q[j].empty() && dis[j]<=a[Q[j].back()]){
					SET.insert(pii(c[Q[j].back()], -Q[j].back()));
					Q[j].pop_back();
				}
			}
		}else if (type == 2){
			int pos, less; cin >> pos >> less; pos--;
			if (SET.find(pii(c[pos], -pos))!=SET.end()){
				SET.erase (pii(c[pos], -pos)); c[pos]-= less;
				SET.insert(pii(c[pos], -pos));
			}else
				c[pos]-=less;
		}else if (type == 3){
			if (SET.empty())
				cout << 0 << endl;
			else{
				set <pii> :: iterator it = SET.end(); it--;
				pii end = *it; SET.erase(end);
				cout << end.first << endl;
			}
		}else{
			assert(false);
		}
	}
	return 0;
}