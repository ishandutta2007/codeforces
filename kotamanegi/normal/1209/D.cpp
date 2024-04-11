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
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
const long double eps = 1e-12;
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<pair<int, int>> inputs;
int visited[300000];
vector<int> vertexs[300000];
int done[300000] = {};
int eaten[300000];
int main(){
	iostream::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	REP(i, k) {
		int a, b;
		cin >> a >> b;
		vertexs[a].push_back(i);
		vertexs[b].push_back(i);
		inputs.push_back(make_pair(a, b));
	}
	queue<int> next;
	int ans = 0;
	REP(i, k) {
		if (visited[i] == 0) {
			visited[i] = 1;
			next.push(i);
			while (next.empty() == false) {
				int now = next.front();
				next.pop();
				if (eaten[inputs[now].first] + eaten[inputs[now].second] == 2)ans++;
				eaten[inputs[now].first] = 1;
				eaten[inputs[now].second] = 1;
				if (done[inputs[now].first] == 0) {
					done[inputs[now].first] = 1;
					for (int q = 0; q < vertexs[inputs[now].first].size(); ++q) {
						int next_go = vertexs[inputs[now].first][q];
						if (visited[next_go] == 0) {
							visited[next_go] = 1;
							next.push(next_go);
						}
					}
				}
				if (done[inputs[now].second] == 0) {
					done[inputs[now].second] = 1;
					for (int q = 0; q < vertexs[inputs[now].second].size(); ++q) {
						int next_go = vertexs[inputs[now].second][q];
						if (visited[next_go] == 0) {
							visited[next_go] = 1;
							next.push(next_go);
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}