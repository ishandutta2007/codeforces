
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

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n, a, b;

	scanf("%d %d %d", &n, &a, &b);

	if(n > a * b) {
		printf("-1\n");
		return true;
	}

	vec< vec< int > > mat(a, vec< int >(b));

	int cur, i, j;

	cur = 1;
	i = 0;
	j = 0;

	while(cur <= n) {
		
		mat[i][j] = cur;

		if(cur + 2 > n) break;

		if(j + 2 < b) j += 2;
		else {
			if(i + 1 < a) {
			    if(b > 1) {
    				i++;
    				j = (i % 2 == 0?0 : 1);
			    }else {
			        i += 2;
			    }
			}else {
				printf("-1\n");
				return true;
			}
		}

		cur += 2;
	}

	if(b > 1) i = 0, j = 1;
	else i = 1, j = 0;

	cur = 2;

	while(cur <= n) {
		
		mat[i][j] = cur;

		if(cur + 2 > n) break;

		if(j + 2 < b) j += 2;
		else {
			if(i + 1 < a) {
			    if(b > 1) {
    				i++;
    				j = (i % 2 == 0?1 : 0);
			    }else {
			        i += 2;
			    }
			}else {
				printf("-1\n");
				return true;
			}
		}

		cur += 2;
	}

	for(int i = 0;i < a;i++) {
		for(int j = 0;j < b;j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}