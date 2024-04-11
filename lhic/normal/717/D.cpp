#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int B = 7;
const int MAXN = 128;

struct kek
{
	ld a[MAXN];
};

kek k1;

kek merg(kek a, kek b)
{
	kek c;
	memset(c.a, 0, sizeof(c.a));
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			c.a[i ^ j] += a.a[i] * b.a[j];
		}
	}
	return c;
}

kek pw(int n)
{
	if (n == 1) return k1;
	kek v = pw(n / 2);
	v = merg(v, v);
	if (n % 2) v = merg(v, k1);
	return v;
}


int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	memset(k1.a, 0, sizeof(k1.a));
	int n, x;
	cin >> n >> x;
	for (int i = 0; i <= x; i++) cin >> k1.a[i];
	cout.setf(ios::fixed);
	cout.precision(20);
	kek kk = pw(n);
	cout << 1.0 - kk.a[0] << endl;
	return 0;
}