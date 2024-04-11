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

const int Maxn = 200005;

map <ll, ll> M;
int n;
int a[Maxn];
int x;
vector <ll> rem[Maxn];

ll getX(ll b1, ll a1, ll b2, ll a2)
{
	ll a = a1 - a2, b = b2 - b1;
	if (a < 0) return 0;
	return a / b + ll(a % b > 0);
}

void Add(ll b, ll a)
{
	map <ll, ll>::iterator it = M.find(b);
	if (it != M.end() && it->second <= a) return;
	M[b] = a;
	it = M.find(b);
	if (it != M.begin()) {
		it--;
		ll X = getX(it->first, it->second, b, a);
		if (X <= x) { M.erase(b); return; }
		it++;
	}
	it++;
	while (it != M.end()) {
		ll X = getX(b, a, it->first, it->second);
		if (X <= x) M.erase(it++);
		else {
			if (X <= n) rem[X].push_back(b);
			break;
		}
	}
}

void Erase(ll b)
{
	map <ll, ll>::iterator it = M.find(b);
	if (it == M.end()) return;
	ll a = it->second;
	it++;
	while (it != M.end()) {
		ll X = getX(b, a, it->first, it->second);
		if (X <= x) M.erase(it++);
		else {
			if (X <= n) rem[X].push_back(b);
			break;
		}
	}
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ll sum = 0, tot = 0, er = 0;
	ll res = 0;
	for (x = 1; x <= n; x++) {
		sum += a[n - x]; tot += sum; er -= ll(x - 1) * a[n - x];
		Add(sum, er);
		for (int i = 0; i < rem[x].size(); i++)
			Erase(rem[x][i]);
		map <ll, ll>::iterator it = M.end(); it--;
		ll best = it->first * x + it->second;
		res = max(res, tot - min(0ll, best));
	}
	printf("%I64d\n", res);
    return 0;
}