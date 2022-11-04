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

int n,e;
int a[1<<20];
vector <int> adj[1<<20];

int main(){
	cin >> n >> e;
	for (int i=0; i<e; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	queue <int> Q;
	for (int i=0; i<n; i++){
		cin >> a[i];
		if (a[i]==0)
			Q.push(i);
	}
	vector <int> ans;
	while (!Q.empty()){
		int front = Q.front(); Q.pop();
		ans.push_back(front+1);
		for (int i=0; i<(int)adj[front].size(); i++){
			int temp = adj[front][i];
			a[temp]--;
			if (a[temp]==0)
				Q.push(temp);
		}
	}
	cout << ans.size() << endl;
	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}