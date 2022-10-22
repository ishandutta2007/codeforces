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
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 8000000000000000000
int visited[300000] = {};
int main() {
	int n;
	cin >> n;
	vector<int> p;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		p.push_back(tmp - 1);
	}
	int b = 0;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		b += tmp;
	}
	int ans = (b+1)%2;
	int tree_size = 0;
	for (int i = 0;i < n;++i) {
		if (visited[i] == false) {
			tree_size++;
			visited[i] = true;
			int wow = p[i];
			while (true) {
				if (visited[wow] == true) break;
				visited[wow] = true;
				wow = p[wow];
			}
		}
	}
	if (tree_size >= 2) {
		ans += tree_size;
	}
	cout << ans << endl;
	return 0;
}