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

const int MAXN = 70000+10;

bool mark[MAXN];
int n,s;
int par[MAXN],val[MAXN],child[MAXN],prev[MAXN];
pii a[MAXN];

int main(){
	scanf("%d%d", &n, &s);
	LL sum = 0;
	for (int i=0; i<n; i++){
		scanf("%d", &a[i].first);
		a[i].second = i;
		sum+= a[i].first;
	}
	sort(a, a+n);
	if (sum < s || a[n-1].first > s){
		puts("-1");
		return 0;
	}
	s-= a[n-1].first;
	memset(par, -1, sizeof par);
	par[0] = 0;
	set <int> SET;
	for (int i=1; i<=s; i++)
		SET.insert(i);
	for (int i=1; i<=s; i++)
		prev[i] = i-1;
	prev[1] = -1;
	int maxi = 0;
	for (int i=0; i<n-1 && maxi!=s; i++){
		int cur = a[i].first;
		set <int> :: iterator it = SET.upper_bound(min(maxi+cur,s));
		if (it == SET.begin()) continue;
		int last = (it == SET.end()) ? (-1) : (*it); it--;
		int poi  = *it;
		while (poi>=cur){
			if (par[poi-cur] != -1){
				par[poi] = i;
				if (last!=-1)
					prev[last] = prev[poi];
				SET.erase(poi);
				maxi = max(maxi, poi);
			}else
				last = poi;
			poi = prev[poi];
		}
	}
	if (par[s] == -1){
		cout << -1 << endl;
		return 0;
	}
	mark[a[n-1].second] = true;
	while (s){
		mark[a[par[s]].second] = true;
		s-= a[par[s]].first;
	}
	memset(child, -1, sizeof child);
	int last = 0;
	for (int i=0; i<n; i++){
		val[a[i].second] = a[i].first - last;
		if (mark[a[i].second])
			last = 0;
		else
			last = a[i].first;
		if (i!=0 && !mark[a[i-1].second])
			child[a[i].second] = a[i-1].second + 1;
	}
	for (int i=0; i<n; i++){
		printf("%d ", val[i]);
		if (child[i] != -1)
			printf("1 %d\n", child[i]);
		else
			printf("0\n");
	}
	return 0;
}