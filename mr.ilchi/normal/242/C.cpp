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

int x,y,xx,yy,n;
int dis[1<<20];
vector <int> adj[1<<20];
map <pii, int> mp;

void bfs (int start){
	memset(dis,-1,sizeof dis);
	queue <int> Q;
	dis[start] = 0;
	Q.push(start);
	while (!Q.empty()){
		int front = Q.front(); Q.pop();
		for (int i=0; i<(int)adj[front].size(); i++){
			int temp = adj[front][i];
			if (dis[temp] == -1){
				Q.push(temp);
				dis[temp] = dis[front] + 1;
			}
		}
	}
}

int main(){
	cin >> x >> y >> xx >> yy;
	cin >> n;
	int cnt = 0;
	for (int i=0; i<n; i++){
		int row,lo,hi;
		cin >> row >> lo >> hi;
		for (int j=lo; j<=hi; j++)
			if (mp.find(pii(row,j))==mp.end())
				mp[pii(row,j)] = cnt++;
	}
	const int dx[] = {-1,-1,-1,0,0,1,1,1};
	const int dy[] = {-1,0,1,-1,1,-1,0,1};

	for (map <pii, int> :: iterator it = mp.begin(); it!=mp.end(); it++){
		int x = (it->first).first;
		int y = (it->first).second;
		for (int i=0; i<8; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (mp.find(pii(xx,yy))!=mp.end())
				adj[it->second].push_back(mp[pii(xx,yy)]);
		}
	}
	bfs(mp[pii(x,y)]);
	cout << dis[mp[pii(xx,yy)]] << endl;
	return 0;
}