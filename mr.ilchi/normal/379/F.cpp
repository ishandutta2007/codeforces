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

int n,q;
int d0,d1,diam;
int hei[1<<20];
int par[1<<20][21];

inline int dist (int x, int y){
	int ans = hei[x] + hei[y]; 
	if (hei[x] > hei[y]) swap(x,y);
	for (int i=20; i>=0; i--) if (hei[par[y][i]] >= hei[x]) y = par[y][i];
	for (int i=20; i>=0; i--) if (par[x][i] != par[y][i]) x=par[x][i], y=par[y][i];
	if (x != y) x = par[x][0];
	return ans - 2 * hei[x];
}

inline void add (int v){
	par[n][0] = v;
	hei[n] = hei[v] + 1;
	for (int i=1; i<=20; i++)
		par[n][i] = par[par[n][i-1]][i-1];
	int tmp = dist(n, d0);
	if (diam < tmp) diam = tmp, d1 = n;
	tmp = dist(n, d1);
	if (diam < tmp) diam = tmp, d0 = n;
	n++;
}

int main(){
	scanf("%d", &q);
	d0 = d1 = 0, diam = 0;
	n = 1;
	add(0);
	add(0);
	add(0);
	for (int o=0; o<q; o++){
		int tmp; scanf("%d", &tmp);
		tmp--;
		add(tmp);
		add(tmp);
		printf("%d\n", diam);
	}
	return 0;
}