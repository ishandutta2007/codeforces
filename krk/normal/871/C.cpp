#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int n;
int X[Maxn], Y[Maxn];
map <int, vector <int> > mX, mY;
set <int> hasX, hasY;
bool tk[Maxn];
int res = 1;

int Mult(int siz)
{
	int res = 1;
	for (int i = 0; i < hasX.size() + hasY.size(); i++)
		res = ll(res) * 2 % mod;
	if (siz < hasX.size() + hasY.size())
		res = (res - 1 + mod) % mod;
	return res;
}

int Fill(int v)
{
	if (tk[v]) return 0;
	tk[v] = true; int res = 1;
	hasX.insert(X[v]); hasY.insert(Y[v]);
	map <int, vector <int> >::iterator it = mX.find(X[v]);
	while (!it->second.empty()) {
		int u = it->second.back(); it->second.pop_back();
		res += Fill(u);
	}
	it = mY.find(Y[v]);
	while (!it->second.empty()) {
		int u = it->second.back(); it->second.pop_back();
		res += Fill(u);
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		mX[X[i]].push_back(i); mY[Y[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) if (!tk[i]) {
		hasX.clear(); hasY.clear();
		res = ll(res) * Mult(Fill(i)) % mod;
	}
	printf("%d\n", res);
	return 0;
}