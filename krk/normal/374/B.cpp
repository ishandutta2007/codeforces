#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ii;

const int Maxn = 100005;

string a;
ii best[Maxn];

void Better(ii &a, const ii &b)
{
	if (b.first > a.first) a = b;
	else if (b.first == a.first) a.second += b.second;
}

int main()
{
	getline(cin, a);
	best[0] = best[1] = ii(0, 1);
	for (int i = 2; i <= a.length(); i++) {
		best[i] = ii(-1, 0);
		if (a[i - 1] - '0' + a[i - 2] - '0' == 9)
			Better(best[i], ii(best[i - 2].first + 1, best[i - 2].second));
		Better(best[i], best[i - 1]);
	}
	printf("%I64d\n", best[a.length()].second);
	return 0;
}