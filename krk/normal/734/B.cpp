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

int k2, k3, k5, k6;
ll res;

int main() 
{
	scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
	int tk = min(min(k2, k5), k6);
	res = ll(tk) * 256;
	k2 -= tk; k5 -= tk; k6 -= tk;
	tk = min(k3, k2);
	res += ll(tk) * 32;
	cout << res << endl;
    return 0;
}