/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 1000 + 5;

char mat[maxN][maxN];
int n,m;
int dis[2*maxN];

int main(){
	
	cin >> n >> m;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> mat[i][j];

	if (n==1){
		cout << 1 << endl;
		return 0;
	}

	memset (dis,-1,sizeof dis);

	queue <int> Q; Q.push(n); dis[n] = 0;

	while (!Q.empty()){
		
		int front = Q.front(); Q.pop();

		if (front<=n){
			for (int j=1; j<=m; j++) if (mat[front][j]=='#' && dis[j+n]==-1){
				Q.push(j+n);
				dis[j+n] = dis[front] + 1;
			}
		}
		else{
			for (int i=1; i<=n; i++) if (mat[i][front-n]=='#' && dis[i]==-1){
				Q.push(i);
				dis[i] = dis[front] + 1;
			}
		}
	}

	cout << dis[1] << endl;

	return 0;
}