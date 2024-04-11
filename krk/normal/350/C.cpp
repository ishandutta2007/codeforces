#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
ii xy[Maxn];
vector <int> res1, res2, res3;

bool Less(const ii &a, const ii &b)
{
	return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

void Write(int a, int b, int c) { res1.push_back(a); res2.push_back(b); res3.push_back(c); }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &xy[i].first, &xy[i].second);
	sort(xy, xy + n, Less);
	for (int i = 0; i < n; i++) {
		if (xy[i].first < 0) Write(1, -xy[i].first, 'L');
		else if (xy[i].first > 0) Write(1, xy[i].first, 'R');
		if (xy[i].second < 0) Write(1, -xy[i].second, 'D');
		else if (xy[i].second > 0) Write(1, xy[i].second, 'U');
		Write(2, 0, 0);
		if (xy[i].second < 0) Write(1, -xy[i].second, 'U');
		else if (xy[i].second > 0) Write(1, xy[i].second, 'D');
		if (xy[i].first < 0) Write(1, -xy[i].first, 'R');
		else if (xy[i].first > 0) Write(1, xy[i].first, 'L');
		Write(3, 0, 0);
	}
	printf("%d\n", res1.size());
	for (int i = 0; i < res1.size(); i++) {
		printf("%d", res1[i]);
		if (res1[i] == 1) printf(" %d %c", res2[i], res3[i]);
		printf("\n");
	}
	return 0;
}