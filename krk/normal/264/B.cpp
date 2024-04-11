#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int best[Maxn];
vector <int> tmp;
int res = 1;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		tmp.clear();
		for (int i = 2; i * i <= a; i++)
			if (a % i == 0) {
				tmp.push_back(i);
				do a /= i;
				while (a % i == 0);
			}
		if (a > 1) tmp.push_back(a);
		int bet = 0;
		for (int i = 0; i < tmp.size(); i++)
			bet = max(bet, best[tmp[i]]);
		for (int i = 0; i < tmp.size(); i++) {
			best[tmp[i]] = bet + 1;
			res = max(res, best[tmp[i]]);
		}
	}
	printf("%d\n", res);
	return 0;
}