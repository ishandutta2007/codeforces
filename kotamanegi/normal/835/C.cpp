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
#include<fstream>
#include <unordered_map>  
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define f(n) for(int i=0;i<n;++i)
#define REP(i,n) for(long long i = 0;i < n;++i)
int grid[200][200][20] = {};
int rui[20][200][200] = {};
int main() {
	int n, queue, c;
	scanf("%d%d%d", &n, &queue, &c);
	REP(i, n) {
		int x, y, s;
		scanf("%d%d%d", &x, &y, &s);
		grid[x][y][s]++;
	}
	for (int tee = 0;tee <= 10;++tee) {
		for (int q = 1;q <= 100;++q) {
	for (int i = 1;i <= 100;++i) {
				rui[tee][i][q] = rui[tee][i - 1][q] + grid[i][q][tee];
			}
		}
	}
	for (int tee = 0;tee <= 10;++tee) {
	for (int i = 1;i <= 100;++i) {
		for (int q = 1;q <= 100;++q) {
				rui[tee][i][q] = rui[tee][i][q - 1] + rui[tee][i][q];
			}
		}
	}
	REP(qwq, queue) {
		int a, b, d, e, f;
		cin >> a >> b >> d >> e >> f;
		int cnt[20] = {};
		int ans = 0;
		for (int tee = 0;tee <= 10;++tee) {
			cnt[tee] += rui[tee][e][f] + rui[tee][b-1][d-1];
			cnt[tee] -= rui[tee][b-1][f] + rui[tee][e][d-1];
			ans += cnt[tee] * ((a + tee) % (c + 1));
		}
		cout << ans << endl;
	}
	return 0;
}