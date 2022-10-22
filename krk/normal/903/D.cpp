#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll lim = 1000000000000000000ll;
const int Maxn = 200005;

int n;
int a[Maxn];
map <int, int> M;
ll p1, p2;
ll n1, n2;

int Count(int x)
{
	map <int, int>::iterator it = M.find(x);
	return it == M.end()? 0: it->second;
}

void Print(bool neg, ll a, ll b)
{
	if (neg) printf("-");
	if (a == 0) printf("%I64d\n", b);
	else {
		printf("%I64d", a);
		stringstream ss; ss << b;
		string s; ss >> s;
		if (s.length() < 18) s = string(18 - int(s.length()), '0') + s;
		printf("%s\n", s.c_str());
	}
}

void Sub(ll &a1, ll &b1, ll a2, ll b2)
{
	b1 -= b2;
	if (b1 < 0) {
		b1 += lim; a1--;
	}
	a1 -= a2;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ll sum = 0;
	for (int i = n; i > 0; i--) {
		int cnt = n - i;
		ll cursum = sum;
		for (int j = a[i] - 1; j <= a[i] + 1; j++) {
			int got = Count(j);
			cnt -= got; cursum -= ll(got) * j;
		}
		cursum -= ll(cnt) * a[i];
		if (cursum >= 0) {
			p2 += cursum;
			if (p2 >= lim) {
				p1 += p2 / lim;
				p2 %= lim;
			}
		} else {
			cursum = -cursum;
			n2 += cursum;
			if (n2 >= lim) {
				n1 += n2 / lim;
				n2 %= lim;
			}
		}
		sum += a[i]; M[a[i]]++;
	}
	if (p1 > n1 || p1 == n1 && p2 >= n2) {
		Sub(p1, p2, n1, n2); Print(false, p1, p2);
	} else {
		Sub(n1, n2, p1, p2); Print(true, n1, n2);
	}
	return 0;
}