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

int n;
int vote[1<<20];
vector <int> q[1<<20];

struct cmp{
	bool operator () (const int &a, const int &b){
		if (q[a].size() != q[b].size())
			return q[a].size() > q[b].size();
		if (q[a].back() != q[b].back())
			return q[a].back() < q[b].back();
		return a < b;
	}
};

int main(){
	scanf("%d", &n);
	int tot = 0;
	set < pair<pair<int,int>, int>,  greater < pair<pair<int,int>, int> > > SET;
	for (int i=0; i<n; i++){
		int a,b; scanf("%d%d", &a, &b);
		tot+= b;
		SET.insert(make_pair(pair<int,int>(b,a), i));
	}
	int ans = tot;
	set <int, cmp> have;
	for (int i=n-1; i>0 && !SET.empty(); i--){
		int current = i+1;
		while (true){
			if (!have.empty() && (int)q[*have.begin()].size()==i){
				int begin = *have.begin(); have.erase(begin);
				tot+= q[begin].back(); q[begin].pop_back();
				current++;
				if (!q[begin].empty())
					have.insert(begin);
			}else if (!SET.empty() && current>i){
				pair<int,int> begin = SET.begin()->first; SET.erase(SET.begin());
				if (begin.second == 0)
					continue;
				if (vote[begin.second]+1 < i){
					current--;
					tot-= begin.first;
					vote[begin.second]++;
					have.erase(begin.second);
					q[begin.second].push_back(begin.first);
					have.insert(begin.second);
				}
			}else
				break;
		}
		if (current == i)
			ans = min(ans, tot);
	}
	printf("%d\n", ans);
	return 0;
}