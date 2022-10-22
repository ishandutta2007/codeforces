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
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
long long scoring[400000] = {};
int main(){
	iostream::sync_with_stdio(false);
	long long n, m;
	cin >> n >> m;
	vector<pair<long long, long long>> input;
	vector<tuple<long long, long long, long long, long long>> vertexs;
	REP(i, n) {
		long long a, b;
		cin >> a >> b;
		input.push_back(make_pair(a, b));
		vertexs.push_back(make_tuple(a - b, a, b, i));
	}
	sort(vertexs.begin(), vertexs.end());
	long long bobo = 0;
	for (int i = 0; i < n; ++i) {
		bobo += get<2>(vertexs[i]);
	}
	for (int i = 0; i < n; ++i) {
		bobo -= get<2>(vertexs[i]);
		scoring[get<3>(vertexs[i])] = bobo;
		scoring[get<3>(vertexs[i])] += (long long)(n - i - 1) * get<1>(vertexs[i]);
		scoring[get<3>(vertexs[i])] += (long long)(i)* get<2>(vertexs[i]);
		bobo += get<1>(vertexs[i]);
	}
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		long long hoge = min(input[a].first + input[b].second, input[a].second + input[b].first);
		scoring[a] -= hoge;
		scoring[b] -= hoge;
	}
	REP(i, n) {
		if (i != 0) cout << " ";
		cout << scoring[i];
	}
	cout << endl;
	return 0;
}