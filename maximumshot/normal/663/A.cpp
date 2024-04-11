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

	int plus = 1, minus = 0;

	vec< int > a;

	a.push_back(1);

	char ty;

	while(scanf(" %c", &ty) == 1) {
		if(ty == '+') plus++, a.push_back(1);
		else if(ty == '-') minus++, a.push_back(-1);
		else if(ty == '=') break;
	}

	int n;

	scanf("%d", &n);

	if(plus - minus * n > n || plus * n - minus < n) {
		printf("Impossible\n");
		return true;
	}

	printf("Possible\n");

	vec< int > ans((int)a.size());

	plus--;

	if(plus >= minus) {
		int val = plus;
		for(int i = 1;i < (int)a.size();i++) {
			if(a[i] == 1) ans[i] = 1;
			else {
				if(val - n >= minus - 1) ans[i] = n;
				else { // val - x == minus - 1
					ans[i] = val - minus + 1;
				}
				minus--;
				val -= ans[i];
			}
		}
		ans[0] = n - val;
	}else {
		int val = minus;
		for(int i = 1;i < (int)a.size();i++) {
			if(a[i] == 1) {
				if(val - n >= plus - 1) ans[i] = n;
				else { // val - x == plus - 1
					ans[i] = val - plus + 1;
				}
				plus--;
				val -= ans[i];
			}else ans[i] = 1;
		}
		ans[0] = n;
	}

	for(int i = 0;i < (int)a.size();i++) {
		if(i > 0) {
			if(a[i] == 1) printf("+ ");
			else printf("- ");
		}
		printf("%d ", ans[i]);
	}

	printf("= %d\n", n);

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}