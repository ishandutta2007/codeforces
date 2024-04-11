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

const int Maxn = 1005;

int n;
ll a[Maxn], b[Maxn];
ll res;

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++) {
		ll cura = 0, curb = 0;
		for (int j = i; j <= n; j++) {
			cura |= a[j]; curb |= b[j];
			res = max(res, cura + curb);
		}
	}
	cout << res << endl;
    return 0;
}