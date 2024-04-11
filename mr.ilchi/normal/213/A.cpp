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

const int MAXN = 200+10;

bool mark[MAXN];
int n;
int a[MAXN],d[MAXN],dd[MAXN];
queue <int> Q[3];
vector <int> adj[MAXN];

int main(){
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		a[i]--;
	}
	for (int i=1; i<=n; i++){
		cin >> dd[i];
		for (int j=1; j<=dd[i]; j++){
			int x; cin >> x;
			adj[x].push_back(i);
		}
	}
	int ans = (1<<30);
	for (int st=0; st<3; st++){
		memset(mark,false,sizeof mark);
		for (int i=1; i<=n; i++)
			d[i] = dd[i];
		for (int i=1; i<=n; i++) if (d[i]==0){
			mark[i]=true;
			Q[a[i]].push(i);
		}	
		int dis = -1;
		for (int cur=st; true; (cur=(cur+1)%3)){
			if (Q[0].empty() && Q[1].empty() && Q[2].empty())
				break;
			dis++;
			while (!Q[cur].empty()){
				int front = Q[cur].front(); Q[cur].pop();
				for (int i=0; i<(int)adj[front].size(); i++){
					int tmp = adj[front][i];
					d[tmp]--;
					if (d[tmp]==0){
						mark[tmp] = true;
						Q[a[tmp]].push(tmp);
					}
				}
			}
		}
		ans = min(ans,n+dis);
	}
	cout << ans << endl;
	return 0;
}