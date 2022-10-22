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

const int Maxn = 100005;
const ll Inf = 10000000000000000ll;

int n, k;
vector <ll> pw;
map <ll, int> M;
ll res;

int Get(ll val)
{
	map <ll, int>::iterator it = M.find(val);
	return it == M.end()? 0: it->second;
}

int main() 
{
	scanf("%d %d", &n, &k);
	pw.push_back(1);
	if (k == -1) pw.push_back(-1);
	if (abs(k) > 1)
		while (abs(pw.back()) < Inf) pw.push_back(pw.back() * k);
	M[0]++;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a); cur += a;
		for (int j = 0; j < pw.size(); j++)
			res += Get(cur - pw[j]);
		M[cur]++;
	}
	printf("%I64d\n", res);
    return 0;
}