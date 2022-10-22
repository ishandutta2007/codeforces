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
vector<int> vertexs[200000];
int sizing[200000] = {};
int color[200000] = {};
int main() {
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		cin >> color[i];
	}
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		vertexs[b].push_back(a);
		sizing[a]++;
	}
	int ans = 0;
	queue<int> nexting[2];
	for (int q = 0;q < n;++q) {
		if (sizing[q] == 0) {
			nexting[color[q]].push(q);
		}
	}
	for (ans = 0;nexting[0].empty() == false||nexting[1].empty() == false;ans++) {
		while (nexting[ans % 2].empty() == false) {
			int now = nexting[ans % 2].front();
			nexting[ans % 2].pop();
			for (int q = 0;q < vertexs[now].size();++q) {
				sizing[vertexs[now][q]]--;
				if (sizing[vertexs[now][q]] == 0) {
					nexting[color[vertexs[now][q]]].push(vertexs[now][q]);
				}
			}
		}
	}
	cout << ans / 2 << endl;
	return 0;
}