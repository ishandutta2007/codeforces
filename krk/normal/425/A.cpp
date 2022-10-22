#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;

int n, k;
int a[Maxn];
vector <ii> nums;
int best = -1000000000;

int canGet(int l, int r)
{
	int res = 0;
	int i = 0, j = nums.size() - 1, lft = k;
	while (lft && i < j) {
		while ((nums[i].second < l || nums[i].second > r) && i < j)
			i++;
		while (l <= nums[j].second && nums[j].second <= r && i < j)
			j--;
		if (i < j) {
			res += nums[j].first - nums[i].first;
			lft--;
			i++; j--;
		}
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		nums.push_back(ii(a[i], i));
		best = max(best, a[i]);
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int l = i; l <= j; l++)
				sum += a[l];
			sum += canGet(i, j);
			best = max(best, sum);
		}
	printf("%d\n", best);
	return 0;
}