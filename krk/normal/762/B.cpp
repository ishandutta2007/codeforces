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

int a, b, c;
int m;
vector <int> A, B;
int res1;
ll res2;

int main() 
{
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &m);
	char str[10];
	while (m--) {
		int cost; scanf("%d %s", &cost, str);
		if (str[0] == 'U') A.push_back(cost);
		else if (str[0] == 'P') B.push_back(cost);
	}
	sort(A.rbegin(), A.rend()); sort(B.rbegin(), B.rend());
	while (a > 0 && !A.empty()) {
		res1++; res2 += A.back();
		a--; A.pop_back();
	}
	while (b > 0 && !B.empty()) {
		res1++; res2 += B.back();
		b--; B.pop_back();
	}
	while (c > 0 && (!A.empty() || !B.empty())) {
		if (!A.empty() && (B.empty() || A.back() <= B.back())) {
			res1++; res2 += A.back();
			A.pop_back();
		} else {
			res1++; res2 += B.back();
			B.pop_back();
		}
		c--;
	}
	printf("%d %I64d\n", res1, res2);
    return 0;
}