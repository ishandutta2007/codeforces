#define _CRT_SECURE_NO_WARNINGS
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
#define LONGINF 1000000000000000000
int main() {
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	long long ans = LONGINF;
	for (int i = 0;i < 10;++i) {
		for (int q = 0;q < 10;++q) {
			for (int j = 0;j < 10;++j) {
				int wow = i + 2 * q + 3 * j;
				if ((n + wow) % 4 == 0) {
					ans = min(ans, i*a + q*b + c*j);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}