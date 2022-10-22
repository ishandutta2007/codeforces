#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

int n, m;
set <int> S;
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	int a; scanf("%d", &a); a--;
	for (int i = 1; i * i <= a; i++)
		if (a % i == 0) { 
			if (i % 2) S.insert(i); 
			if (a / i % 2) S.insert(a / i); 
		}
	for (int i = 1; i < n; i++) {
		scanf("%d", &a); a--;
		for (set <int>::iterator it = S.begin(); it != S.end(); )
			if (a % *it == 0) it++;
			else S.erase(it++);
	}
	for (set <int>::iterator it = S.begin(); it != S.end(); it++) {
		int x = *it;
		while (x <= m) {
		 	res += m - x;
			x *= 2;
		}
	}
	printf("%I64d\n", res);
	return 0;
}