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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int n,k;
int dis[1<<20][2];
string s[2];

void bfs (){

	memset(dis,-1,sizeof dis);

	queue <pii> Q; 
	Q.push(pii(0,0));
	dis[0][0] = 0;

	while (!Q.empty()){
		
		pii front = Q.front(); Q.pop();

		int x = front.first;
		int y = front.second;

		if (dis[x][y] > x)
			continue;

		if (x+k>=n){
			cout << "YES" << endl;
			exit(0);
		}

		if (s[1-y][x+k]!='X' && dis[x+k][1-y]==-1){
			dis[x+k][1-y] = dis[x][y] + 1;
			Q.push(pii(x+k,1-y));
		}

		if (x!=0 && s[y][x-1]!='X' && dis[x-1][y]==-1){
			dis[x-1][y] = dis[x][y] + 1;
			Q.push(pii(x-1,y));
		}

		if (s[y][x+1]!='X' && dis[x+1][y]==-1){
			dis[x+1][y] = dis[x][y] + 1;
			Q.push(pii(x+1,y));
		}
	}
}

int main(){
	
	cin >> n >> k;
	cin >> s[0] >> s[1];

	bfs();

	cout << "NO" << endl;

	return 0;
}