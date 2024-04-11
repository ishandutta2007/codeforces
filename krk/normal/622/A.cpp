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

ll n;

int main() 
{
	ll cur = 1;
	scanf("%I64d", &n);
	while (cur < n) {
		n -= cur; cur++;
	}
	printf("%I64d\n", n);
    return 0;
}