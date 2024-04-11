#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n;
int w[Maxn], h[Maxn];
int res = 2000000000;

bool getF(int x, int &sum)
{
	sum = 0;
	int lft = n / 2;
	priority_queue <int> Q;
	for (int i = 0; i < n; i++)
		if (h[i] > x)
			if (w[i] > x) return false;
			else { sum += h[i]; lft--; }
		else {
			sum += w[i];
			if (w[i] <= x && w[i] - h[i] > 0) Q.push(w[i] - h[i]);
		}
	if (lft < 0) return false;
	while (lft && !Q.empty()) {
		sum -= Q.top(); Q.pop();
		lft--;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &w[i], &h[i]);
	int sum;
	for (int h = 1; h <= 1000; h++)
		if (getF(h, sum)) res = min(res, h * sum);
	printf("%d\n", res);
	return 0;
}