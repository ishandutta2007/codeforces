#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 400000;

int arr[MAX_N];

int qq[MAX_N];

long long ans[MAX_N];

vector<pair<int, int>> vv;
vector<pair<int, int>> vv1;

int qqq[MAX_N];


int n, q;
int q2;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int q = a % b;
		a = b;
		b = q;
	}
	return a;
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &qqq[i]);
	}
	for (int i = 0; i < q; ++i)
		qq[i] = qqq[i];
	sort(qq, qq + q);
	int q2 = unique(qq, qq + q) - qq;
	vv.push_back({0, -1});
	for (int i = 0; i < n; ++i)
	{
		if (vv[vv.size() - 1].first == 0 || vv[vv.size() - 1].first % arr[i] != 0)
			vv.push_back({arr[i], i});
		vv1.clear();
		vv1.push_back(vv[0]);
		for (int j = 1; j < (int)vv.size(); ++j)
		{
			int x = gcd(vv[j].first, arr[i]);
			if (vv1[vv1.size() - 1].first != x)
				vv1.push_back({x, vv[j].second});
		}
		swap(vv1, vv);
		for (int j = 1; j < (int)vv.size() - 1; ++j)
		{
			int k = lower_bound(qq, qq + q2, vv[j].first) - qq;
			if (qq[k] == vv[j].first)
				ans[k] += vv[j + 1].second - vv[j].second;
		}
		int k = lower_bound(qq, qq + q2, vv[vv.size() - 1].first) - qq;
		if (qq[k] == vv[vv.size() - 1].first)
			ans[k] += i + 1 - vv[vv.size() - 1].second;
	}
	/*for (int i = 0 ; i < q; ++i)
		printf("%I64d\n", ans[i]);*/
	for (int i = 0 ; i < q; ++i)
	{
		int k = lower_bound(qq, qq + q2, qqq[i]) - qq;
		printf("%I64d\n", ans[k]);
	}
}