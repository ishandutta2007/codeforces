////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 1e5;
int par[N + 5];

priority_queue<pair<int, pair<int,int> > > pq;

int find(int x) {
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

void hora(int tc) {
	int n, m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) par[i] = i;
	int rem1, rem2, ct = -1;
	for(int i = 0;i < m;i++) {
		int u, v, w;
		cin>>u>>v>>w;
		if(i == 0) rem1 = u, rem2 = v;
		else pq.push({-w,{u, v}});
	}
	int mx = 1e9;
	while(!pq.empty()) {
		int c = -pq.top().FI;
		int u = pq.top().SE.FI;
		int v = pq.top().SE.SE;
		pq.pop();
		if(find(u) != find(v)) {
			par[find(u)] = find(v);
			if(find(rem1) == find(rem2)) mx = min(mx, c);
		}
	}
	cout<<mx<<endl;
}

int main(){
	desperate_optimization(6);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}