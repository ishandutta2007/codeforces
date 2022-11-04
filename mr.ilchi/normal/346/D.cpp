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

const int MAXN = 1000000+10;
const int inf = 1000000000;

bool mark[MAXN];
int n,e,s,t;
int dis[MAXN],func[MAXN],out[MAXN];
vector <int> bak[MAXN];

struct cmp{
	inline bool operator () (const int &A, const int &B){
		return dis[A]!=dis[B] ? dis[A]<dis[B] : A<B;
	}
};

inline void dij(){
	for (int i=0; i<n; i++)
		dis[i] = inf;
	dis[t] = 0;
	set <int, cmp> SET;
	SET.insert(t);
	while (!SET.empty()){
		int begin = *SET.begin(); SET.erase(begin);
		mark[begin] = true;
		for (int i=0; i<(int)bak[begin].size(); i++){
			int temp = bak[begin][i];
			if (mark[temp]) continue;
			if (dis[begin]+1 < dis[temp]){
				SET.erase(temp);
				dis[temp] = dis[begin]+1;
				SET.insert(temp);
			}
			out[temp]--;
			func[temp] = max(func[temp], dis[begin]);
			if (out[temp]==0 && func[temp] < dis[temp]){
				SET.erase(temp);
				dis[temp] = func[temp];
				SET.insert(temp);
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &e);
	for (int i=0; i<e; i++){
		int e1,e2; scanf("%d%d", &e1, &e2);
		e1--; e2--;
		bak[e2].push_back(e1);
		out[e1]++;
	}
	scanf("%d%d", &s, &t);
	s--; t--;
	dij();
	if (dis[s] == inf)
		printf("-1\n");
	else
		printf("%d\n", dis[s]);
	return 0;
}