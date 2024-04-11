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

const int Maxm = 10000005;

int mx[Maxm], my[Maxm];
int cnt[Maxm];
int n, l, r;

int main() 
{
	mx[1] = 1;
	for (int i = 2; i < Maxm; i++) if (mx[i] == 0) {
		for (int j = i; j < Maxm; j += i) mx[j] = i;
		cnt[i] = 1;
	}
	cin >> n >> l >> r;
	if (n == 1) { printf("%d\n", r - l + 1); return 0; }
	else if (n == 2) {
		int m = r - l + 1;
		printf("%I64d\n", ll(m) * (m - 1));
		return 0;
	}
	int res = 0;
	for (int i = 1; i < Maxm; i++) {
	    if (i == 1) my[i] = 1;
	    else {
	    	if (cnt[i] == 0)
	    		if (mx[i] != mx[i / mx[i]]) cnt[i] = 1;
	    		else cnt[i] = cnt[i / mx[i]] + 1;
	        my[i] = my[i / mx[i]];
	        if (cnt[i] % 2 == 1) my[i] *= mx[i];
	    }
	    if (i < l) continue;
		for (int j = i + my[i]; j < Maxm && ll(j) * j / i <= r; j += my[i]) {
			ll prv = i, cur = j, tmp, len = 2;
			while (cur * cur % prv == 0 && len < n) {
				tmp = prv; prv = cur; cur = cur * cur / tmp;
				if (cur > r) break;
				len++;
			}
			res += len == n;
		}
	}
	printf("%d\n", 2 * res);
    return 0;
}