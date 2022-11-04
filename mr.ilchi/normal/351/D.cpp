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

const int MAXN = 100000 +10;
const int MAXT = (1<<18)+10;
const int inf = 1000000000;

int n,que;
int a[MAXN],mark[MAXN],prev[MAXN],range[MAXN];
int ans[MAXN],lo[MAXN],hi[MAXN];
int mini[MAXT],sum [MAXT];
vector <int> Q[MAXN];

void undo (int root, int lo, int hi, int pos){
	if (lo == hi){
		mini[root] = inf;
		sum [root] = 0;
		return;
	}
	int mid = (lo + hi) / 2;
	if (pos <= mid) 
		undo(root*2, lo, mid, pos);
	else
		undo(root*2+1, mid+1, hi, pos);
	sum [root] = sum[root*2] + sum[root*2+1];
	mini[root] = min(mini[root*2], mini[root*2+1]);
}

void go (int root, int lo, int hi, int pos){
	if (lo == hi){
		mini[root] = range[pos];
		sum [root] = 1;
		return;
	}
	int mid = (lo + hi) / 2;
	if (pos <= mid)
		go(root*2, lo, mid, pos);
	else
		go(root*2+1, mid+1, hi, pos);
	sum [root] = sum[root*2] + sum[root*2+1];
	mini[root] = min(mini[root*2], mini[root*2+1]);
}

pii get (int root, int lo, int hi, int L, int R){
	if (R<lo || hi<L)
		return pii(0, inf);
	if (L<=lo && hi<=R)
		return pii(sum[root], mini[root]);
	int mid = (lo + hi) / 2;
	pii re1 = get(root*2, lo, mid, L, R);
	pii re2 = get(root*2+1, mid+1, hi, L, R);
	return pii(re1.first + re2.first, min(re1.second, re2.second));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	memset(mark, -1, sizeof mark);
	for (int i=0; i<n; i++){
		cin >> a[i];
		a[i]--;
		prev[i] = mark[a[i]];
		mark[a[i]] = i;
	}
	cin >> que;
	for (int i=0; i<que; i++){
		cin >> lo[i] >> hi[i];
		lo[i]--; hi[i]--;
		Q[hi[i]].push_back(i);
	}
	for (int i=0; i<MAXT; i++)
		mini[i] = inf;
	for (int i=0; i<n; i++){
		if (prev[i]!=-1){
			undo(1, 0, n-1, prev[i]);
			if (prev[prev[i]]!=-1 && i-prev[i]!=prev[i]-prev[prev[i]])
				range[i] = prev[prev[i]]+1;
			else
				range[i] = range[prev[i]];
		}else
			range[i] = 0;
		go(1, 0, n-1, i);
		for (int j=0; j<(int)Q[i].size(); j++){
			pii temp = get(1, 0, n-1, lo[Q[i][j]], i);
			ans[Q[i][j]] = temp.first + (temp.second > lo[Q[i][j]]);
		}
	}
	for (int i=0; i<que; i++)
		cout << ans[i] << endl;
	return 0;
}