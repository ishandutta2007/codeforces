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

const int mod = 1000000007;

int n,k,c0,c1;
int C[100][100];
int ans[100][100][2];
int dis[100][100][2];

struct node{
	int x,y,t;
	node () {}
	node (int x, int y, int t) : x(x), y(y), t(t) {}
};

int main(){
	for (int i=0; i<100; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	cin >> n >> k;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		if (temp==50) c0++;
		if (temp==100) c1++;
	}
	memset(dis, -1, sizeof dis);
	dis[c0][c1][0] = 0;
	ans[c0][c1][0] = 1;
	queue <node> Q; 
	Q.push(node(c0,c1,0));
	while (!Q.empty()){
		node front = Q.front(); Q.pop();
		for (int i=0; i<=front.x; i++)
			for (int j=0; j<=front.y; j++) if ((i * 50 + j * 100 <= k) && (i+j>0)){
				int x = c0 - front.x + i;
				int y = c1 - front.y + j;
				int t = 1-front.t;
				if (dis[x][y][t]==-1){
					dis [x][y][t] = dis[front.x][front.y][front.t] + 1;
					Q.push(node(x,y,t)); 
				}
				if (dis[x][y][t] == dis[front.x][front.y][front.t] + 1)
					ans[x][y][t] = (ans[x][y][t] + (LL)ans[front.x][front.y][front.t] * (LL)C[front.x][i] % mod * (LL)C[front.y][j] % mod) % mod;
			}
	}
	cout << dis[c0][c1][1] << endl;
	cout << ans[c0][c1][1] << endl;
	return 0;
}