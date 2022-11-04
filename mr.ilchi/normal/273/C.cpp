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

const int MAXN = 300000 + 100;

bool group[MAXN];
int n,e;
int bad[MAXN];
vector <int> adj[MAXN];

int main(){
	srand(701);
	ios_base::sync_with_stdio(false);
	cin >> n >> e;
	for (int i=0; i<e; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--; 
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	for (int i=0; i<n; i++)
		group[i] = rand()%2;
	queue <int> Q;
	for (int i=0; i<n; i++){
		for (int j=0; j<(int)adj[i].size(); j++)
			bad[i]+= (group[adj[i][j]] == group[i]);
		if (bad[i] > 1)
			Q.push(i);
	}
	while (!Q.empty()){
		int front = Q.front(); Q.pop();
		if (bad[front] <= 1) continue;
		group[front] = 1-group[front];
		bad[front] = adj[front].size() - bad[front];
		for (int i=0; i<(int)adj[front].size(); i++){
			int tmp = adj[front][i];
			if (group[tmp] != group[front])
				bad[tmp]--;
			else{
				bad[tmp]++;
				if (bad[tmp] == 2)
					Q.push(tmp);
			}
		}
	}
	for (int i=0; i<n; i++)
		cout << group[i];
	cout << endl;
	return 0;
}