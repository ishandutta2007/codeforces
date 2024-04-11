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
int k;
vector <ll> dvs;

int main() 
{
	scanf("%I64d %d", &n, &k);
	for (ll i = 1; i * i <= n; i++)
		if (n % i == 0) {
			dvs.push_back(i);
			if (i * i < n) dvs.push_back(n / i);
		}
	sort(dvs.begin(), dvs.end());
	if (dvs.size() < k) printf("-1\n");
	else printf("%I64d\n", dvs[k - 1]); 
    return 0;
}