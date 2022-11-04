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

#define ff first
#define ss second

using namespace std;

typedef long long LL;
typedef long long ll;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<int,int> pie;

const int num = 5 * 7 * 8 * 9 * 11 * 13;

int k;
int dp[1<<20],dis[2][1<<20];
LL a,b;
vector <int> adj[2][1<<20];

void BFS(int index){
	memset(dis[index],-1,sizeof dis[index]);
	queue <int> Q;
	Q.push(0);
	dis[index][0] = 0;
	while (!Q.empty()){
		int front = Q.front(); Q.pop();
		for (int i=0; i<(int)adj[index][front].size(); i++){
			int tmp = adj[index][front][i];
			if (dis[index][tmp] == -1){
				dis[index][tmp] = dis[index][front] + 1;
				Q.push(tmp);
			}
		}
	}
}

int main(){	
	cin >> a >> b >> k;
	swap(a,b);
	if (b-a<1000000){
		dp[0] = 0;
		for (LL i=a+1; i<=b; i++){
			dp[i-a] = dp[i-a-1] + 1;
			for (int j=2; j<=k; j++) if (i - i%j >= a)
				dp[i-a] = min(dp[i-a], dp[i-i%j-a] + 1);
		}
		cout << dp[b-a] << endl;
		return 0;
	}
	for (int i=0; i<num; i++){
		for (int j=2; j<=k; j++){
			adj[0][i].push_back(i - i%j);
			adj[1][i-i%j].push_back(i);
		}
		adj[0][i].push_back((i-1+num)%num);
		adj[1][(i-1+num)%num].push_back(i);
	}
	BFS(0);
	BFS(1);
	int cycle = 1<<30;
	for (int i=1; i<num; i++)
		cycle = min(cycle, dis[0][i] + dis[1][i]);
	LL ans = dis[0][a%num] + dis[1][b%num] + (LL)cycle * (((b-b%num) - (a+((num-(a%num))%num)))/num);
	cout << ans << endl;
	return 0;
}