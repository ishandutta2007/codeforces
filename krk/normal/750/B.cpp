#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll lim = 20000;

int n;

int main() 
{
	ll cur = 0;
	scanf("%d", &n);
	int t; string dr;
	for (int i = 0; i < n; i++) {
		cin >> t >> dr;
		if (cur == 0 && dr != "South" || cur == lim && dr != "North") {
			printf("NO\n"); return 0;
		}
		if (dr == "South") cur += t;
		if (dr == "North") cur -= t;
		if (cur < 0 || cur > lim) { printf("NO\n"); return 0; }
	}
	printf("%s\n", cur == 0? "YES": "NO");
    return 0;
}