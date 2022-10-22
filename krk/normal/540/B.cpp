#include <cstdio>
#include <vector>
using namespace std;

typedef pair <int, bool> ib;

int n, k, p, x, y;
int sum;
vector <int> res;

int main()
{
	scanf("%d %d %d %d %d", &n, &k, &p, &x, &y);
	int hm = 0;
	for (int i = 0; i < k; i++) {
		int a; scanf("%d", &a);
		sum += a;
		hm += a < y;
	}
	if (hm > n / 2) printf("-1\n");
	else {
		int lft = n / 2 - hm;
		for (int i = 0; i < lft && i < n - k; i++) {
			res.push_back(1); sum += 1;
		}
		for (int i = 0; i < n - k - lft; i++) {
			res.push_back(y); sum += y;
		}
		if (sum > x) printf("-1\n");
		else for (int i = 0; i < res.size(); i++)
				printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	}
	return 0;
}