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
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const ll x = 1234567ll;
const ll y = 123456ll;
const ll z = 1234ll;

bool solve() {
	
	int n;

	scanf("%d", &n);

	multiset< int > q;

	char buff[20];
	string t;

	vec< pair< int, int > > res; 

	for(int x, i = 0;i < n;i++) {
		scanf("%s", &buff);
		t = buff;
		if(t == "insert") {
			scanf("%d", &x);
			q.insert(x);
			//printf("insert %d\n", x);
			res.push_back(mp(0, x));
		}else if(t == "getMin") {
			scanf("%d", &x);
			while(!q.empty() && *q.begin() < x) {
				//printf("removeMin\n");
				res.push_back(mp(2, 0));
				q.erase(q.begin());
			}
			if(q.empty() || *q.begin() > x) {
				//printf("insert %d\n", x);
				res.push_back(mp(0, x));
				q.insert(x);
			}
			//printf("getMin %d\n", x);
			res.push_back(mp(1, x));
		}else { // t == removeMin
			if(q.empty()) {
				//printf("insert 1\n");
				res.push_back(mp(0, 1));
				q.insert(1);
			}
			//printf("removeMin\n");
			res.push_back(mp(2, 0));
			q.erase(q.begin());
		}
	}

	printf("%d\n", (int)res.size());
	
	for(auto i : res) {
		if(i.first == 0) {
			printf("insert %d\n", i.second);
		}else if(i.first == 1) {
			printf("getMin %d\n", i.second);
		}else {
			printf("removeMin\n");
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}