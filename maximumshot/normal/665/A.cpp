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

bool solve() {
	
	int a, ta, b, tb;

	scanf("%d %d %d %d", &a, &ta, &b, &tb);

	int st, H, M;

	scanf("%d:%d", &H, &M);

	st = H * 60 + M;

	int res = 0;

	for(int i = 5 * 60;i < 24 * 60;i += b) {
		if(st + ta > i && i + tb > st) res++;
	}



	printf("%d\n", res);

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}