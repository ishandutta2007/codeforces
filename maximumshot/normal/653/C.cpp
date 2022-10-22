#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n;
vec< int > t, p;

bool valid(int pos) {
	if(pos < 1 || pos > n) return 1;
	if(pos == 1) return t[pos] < t[pos + 1];
	else if(pos == n) {
		if(pos % 2 == 1) return t[pos] < t[pos - 1];
		else return t[pos] > t[pos - 1];
	}else {
		if(pos % 2 == 1) return (t[pos - 1] > t[pos] && t[pos] < t[pos + 1]);
		else return (t[pos - 1] < t[pos] && t[pos] > t[pos + 1]);
	}
}

bool check(int add) {
	int res = 1;
	for(auto pos : p) {
		if(!valid(pos)) res = 0;
		if(!valid(pos - 1)) res = 0;
		if(!valid(pos + 1)) res = 0;
	}
	if(!valid(add)) res = 0;
	if(!valid(add - 1)) res = 0;
	if(!valid(add + 1)) res = 0;
	return res;
}

bool solve() {
    
	scanf("%d", &n);
    
	t.resize(n + 1);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &t[i]);
	}

	for(int i = 1;i <= n;i++) {
		if(!valid(i)) p.push_back(i);
	}

	if((int)p.size() > 10) {
		printf("0\n");
		return true;
	}

	vec< pii > ans;
	
	for(auto pos : p) {
		for(int i = 1;i <= n;i++) {
			if(i == pos) continue;
			swap(t[i], t[pos]);
			if(check(i)) ans.push_back(mp(pos, i));
			swap(t[i], t[pos]);
		}
	}

	for(int i = 0;i < (int)ans.size();i++) {
		int u, v;
		tie(u, v) = ans[i];
		if(u > v) swap(u, v);
		ans[i] = mp(u, v);
	}

	sort(ALL(ans));
	ans.resize(unique(ALL(ans)) - ans.begin());

	cout << (int)ans.size() << '\n';

	return true;
}

int main() {

	//swhile(solve());
	solve();
	
	return 0;
}