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
typedef pair<int,int> pii;
typedef complex<double> point;

const int MAXN = 2000+10;
const int MAXW = MAXN*MAXN;

int n,m,code;
int x0[MAXN],yy0[MAXN],x1[MAXN],yy1[MAXN];
int num[MAXN][MAXN];
int par[MAXW],mark[MAXW];
vector <int> adj[MAXW];

void addedge (int x, int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}

vector < pair<int, pii> > normal (vector < pair<int,pii> > Q){
	sort(Q.begin(), Q.end());
	vector < pair<int,pii> > ret;
	for (int i=0; i<(int)Q.size(); i++){
		int lo = Q[i].second.first;
		int maxi = Q[i].second.second;
		int j = i+1;
		while (j < (int)Q.size() && Q[i].first == Q[j].first){
			if (Q[j].second.first > maxi){
				ret.push_back(make_pair(Q[i].first, pii(lo, maxi)));
				lo = Q[j].second.first;
				maxi = Q[j].second.second;
			}else{
				maxi = max(maxi, Q[j].second.second);
			}
			j++;
		}
		ret.push_back(make_pair(Q[i].first, pii(lo,maxi)));
		i = j-1;
	}
	return ret;
}

bool inside (int pos, pii X){
	return pos>=X.first && pos<=X.second;
}

bool can (int len){
	vector < pair<int, pii> > of,am;
	for (int i=0; i<n; i++)
		am.push_back(make_pair(x0[i], pii(yy0[i]-2*len, yy0[i]+2*len)));
	for (int i=0; i<m; i++)
		of.push_back(make_pair(yy1[i], pii(x1[i]-2*len, x1[i]+2*len)));
	
	vector < pair<int, pii> > myof = normal(of);
	vector < pair<int, pii> > myam = normal(am);
	for (int i=0; i<(int)myof.size(); i++)
		for (int j=0; j<(int)myam.size(); j++)
			num[i][j] = -1;
	int tot = 0;
	for (int i=0; i<MAXW; i++) 
		adj[i].clear();
	for (int i=0; i<(int)myof.size(); i++){
		int past = -1;
		for (int j=0; j<(int)myam.size(); j++){
			if (inside(myam[j].first, myof[i].second) && inside(myof[i].first, myam[j].second)){
				num[i][j] = tot++;
				if (past != -1)
					addedge(tot-1, past);
				past = tot-1;
			}
		}
	}
	for (int i=0; i<(int)myam.size(); i++){
		int past = -1;
		for (int j=0; j<(int)myof.size(); j++){
			if (inside(myam[i].first, myof[j].second) && inside(myof[j].first, myam[i].second)){
				if (past != -1)
					addedge(num[j][i], past);
				past = num[j][i];
			}
		}
	}
	code++;
	for (int i=0; i<tot; i++) if (mark[i] != code){
		queue <int> Q;
		Q.push(i);
		par[i] = -1;
		mark[i] = code;
		while (!Q.empty()){
			int front = Q.front(); Q.pop();
			for (int i=0; i<(int)adj[front].size(); i++){
				int tmp = adj[front][i];
				if (mark[tmp]!=code){
					Q.push(tmp);
					mark[tmp] = code;
					par [tmp] = front;
				}else if (par[front] != tmp){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++) { int x,y; cin >> x >> y; x0[i] = x+y, yy0[i] = x-y; }
	for (int i=0; i<m; i++) { int x,y; cin >> x >> y; x1[i] = x+y, yy1[i] = x-y; }
	int lo = 1, hi = (int)1e8, ans = -1;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		if (can(mid))
			hi = mid-1, ans = mid;
		else
			lo = mid+1;
	}
	if (ans == -1)
		cout << "Poor Sereja!" << endl;
	else
		cout << ans << endl;
	return 0;
}