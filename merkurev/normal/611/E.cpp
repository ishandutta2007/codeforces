#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

multiset <int> t;

int ans = 0;
int cnt;

void tryAns()
{
	if (cnt == 1)
	{
		ans ++;
		cnt = 0;
	}
	if (cnt != 0)
		return;
	printf("%d\n", ans);
	exit(0);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
		swap(a, b);
	if (b > c)
		swap(b, c);
	if (a > b)
		swap(a, b);

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		t.insert(x);
	}

	if (*prev(t.end() ) > a + b + c) // OK
	{
		printf("-1");
		return 0;
	}
	cnt = n;

	while (cnt >= 1 && *prev(t.end() ) > b + c) // OK
	{
		cnt--;
		ans++;
		t.erase(prev(t.end() ) );
	}

	while (cnt >= 2 && *t.begin() <= a && *prev(t.end() ) > a + c) // OK
	{
		cnt -= 2;
		ans++;
		t.erase(prev(t.end() ) );
		t.erase(prev(t.upper_bound(a) ) );
	}

	tryAns();

	while (cnt >= 1 && *prev(t.end() ) > a + c) // OK
	{
		cnt--;
		ans++;
		t.erase(prev(t.end() ) );
	}

	tryAns();

	while (cnt >= 2 && *prev(t.end() ) > max(c, a + b) && *t.begin() <= b) // OK
	{
		cnt -= 2;
		ans++;
		t.erase(prev(t.end() ) );
		t.erase(prev(t.upper_bound(b) ) );
	}

	tryAns();


	if (*t.begin() > b)
	{
		int A = c;
		int B = a + b;
		if (A > B)
			swap(A, B);
		while (cnt > 1 && *prev(t.end() ) > B) // OK
		{
			cnt--;
			ans++;
			t.erase(prev(t.end() ) );
		}

		tryAns();

		while (cnt >= 2 && *t.begin() <= A) // OK
		{
			cnt -= 2;
			ans++;
			t.erase(prev(t.upper_bound(B) ) ); // -  while
			t.erase(prev(t.upper_bound(A) ) );
		}
		ans += cnt;
		cnt = 0;
		tryAns();
		throw;
	}

	while (cnt >= 2 && *prev(t.end() ) > c && t.upper_bound(c) != t.begin() ) // OK
	{
		cnt -= 2;
		ans ++;
		t.erase(prev(t.end() ) );
		t.erase(prev(t.upper_bound(c) ) );
	}

	tryAns();

	if (t.upper_bound(c) == t.begin() ) // OK
	{
		ans += cnt;
		cnt = 0;
		tryAns();
		throw;
	}


	while (cnt >= 3 && t.upper_bound(a) != t.begin() && prev(t.upper_bound(b) ) != t.begin() ) // OK
	{
		cnt -= 3;
		ans ++;
		t.erase(prev(t.end() ) );
		t.erase(prev(t.upper_bound(b) ) );
		t.erase(prev(t.upper_bound(a) ) );
	}

	tryAns();

	int A = c;
	int B = a + b;
	if (A > B)
		swap(A, B);

	while (cnt >= 2 && t.upper_bound(A) != t.begin() )
	{
		cnt -= 2;
		ans++;
		t.erase(prev(t.end() ) );
		t.erase(prev(t.upper_bound(A) ) );
	}

	ans += cnt;
	cnt = 0;
	tryAns();
	throw;
}