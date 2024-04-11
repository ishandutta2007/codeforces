#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxl = 3;
const string ins[Maxl + 1] = {"pushBack", "pushStack", "pushQueue", "pushFront"};
const string nam[Maxl] = {"popStack", "popQueue", "popFront"};

int n;
int a[Maxn];
priority_queue <ii> Q;
int taken[Maxn];
int cnt[Maxl];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i]) Q.push(ii(a[i], i));
		else {
			int len = 0;
			while (!Q.empty() && len < Maxl) {
				taken[Q.top().second] = len + 1; Q.pop();
				len++;
			}
			taken[i] = len;
			while (!Q.empty()) Q.pop();
		}
	}
	for (int i = 0; i < n; i++)
		if (a[i]) printf("%s\n", ins[taken[i]].c_str());
		else {
			printf("%d", taken[i]);
			for (int j = 0; j < taken[i]; j++)
				printf(" %s", nam[j].c_str());
			printf("\n");
		}
	return 0;
}