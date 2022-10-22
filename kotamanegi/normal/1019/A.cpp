#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
#define int long long
vector<int> party[200000];
int n, m;
long long solve(int a) {
	vector<int> gea;
	long long ans = 0;
	int required = a - party[1].size();
	for (int i = 2; i <= m; ++i) {
		for (int q = 0; q < party[i].size(); ++q) {
			if (q < a-1LL) {
				gea.push_back(party[i][party[i].size() - 1 - q]);
			}
			else {
				required--;
				ans += party[i][party[i].size()-q - 1];
			}
		}
	}
	if (gea.size() != 0) {
		sort(gea.begin(), gea.end());
	}
	if (gea.size() < required) return LONG_INF;
	REP(i, required) {
		ans += gea[i];
	}
	return ans;
}
#undef int
int main(){
#define int long long
	cin >> n >> m;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		party[a].push_back(b);
	}
	for (int i = 1; i <= m; ++i) {
		sort(party[i].begin(),party[i].end());
	}
	long long ans = LONG_INF;
	for (int i = party[1].size(); i <= n; ++i) {
		ans = min(ans, solve(i));
	}
	cout << ans << endl;
	return 0;
}