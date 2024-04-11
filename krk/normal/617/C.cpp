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
typedef pair <ll, ll> llll;

const int Maxn = 2005;
const ll Inf = 9000000000000000000ll;

int n, X1, Y1, X2, Y2;
int X[Maxn], Y[Maxn];
vector <llll> V;
ll res = Inf;

ll Dist(ll ax, ll ay) { return ax * ax + ay * ay; }

ll Check(int from)
{
	ll mx = 0;
	for (int i = from; i < V.size(); i++)
		mx = max(mx, V[i].second);
	return mx;
}

int main() 
{
	scanf("%d %d %d %d %d", &n, &X1, &Y1, &X2, &Y2);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		ll d1 = Dist(X1 - X[i], Y1 - Y[i]);
		ll d2 = Dist(X2 - X[i], Y2 - Y[i]);
		V.push_back(llll(d1, d2));
	}
	sort(V.begin(), V.end());
	res = min(res, Check(0));
	for (int i = 0; i < V.size(); i++)
		res = min(res, V[i].first + Check(i + 1));
	printf("%I64d\n", res);
    return 0;
}