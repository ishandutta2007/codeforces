#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve()
{
	int n;

	scanf("%d", &n);

	vec< pair< int, int> > a(n);
	for(int l, r, i = 0;i < n;i++) {
		scanf("%d %d", &l, &r);
		a[i] = mp(r, l);
	}

	sort(ALL(a));

	int ans = 0;
	int last = 0;

	for(int i = 0;i < n;i++) {
		int l, r;
		l = a[i].second;
		r = a[i].first;
		if(l <= last) continue;
		ans++;
		last = r;
	}

	cout << ans << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}