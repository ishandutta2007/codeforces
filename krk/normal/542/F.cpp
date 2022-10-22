#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n, T;
ii tq[Maxn];
vector <int> cur;

bool Less(const int &a, const int &b) { return a > b; }

void Next()
{
	vector <int> nw;
	for (int i = 0; i < cur.size(); i += 2) {
		int val = cur[i] + (i + 1 < cur.size()? cur[i + 1]: 0);
		nw.push_back(val);
	}
	cur = nw;
}

int main()
{
	scanf("%d %d", &n, &T);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &tq[i].first, &tq[i].second);
	sort(tq, tq + n);
	int j = 0;
	for (int i = 1; i <= T; i++) {
		Next();
		while (j < n && tq[j].first == i) {
			cur.push_back(tq[j].second);
			j++;
		}
		sort(cur.begin(), cur.end(), Less);
	}
	printf("%d\n", cur[0]);
	return 0;
}