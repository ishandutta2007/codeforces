#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
int id[Maxn];
ii S[Maxn];
int len;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &id[i]);
	S[len++] = ii(id[0], -1);
	for (int i = 1; i < n; i++) {
		int cnt = 1;
		while (S[len - 1].first <= id[i] && S[len - 1].second != -1) {
			cnt = S[len - 1].second;
			while (S[len - 1].second == cnt) len--;
			cnt++;
		}
		if (S[len - 1].second == -1 && S[len - 1].first <= id[i]) S[len++] = ii(id[i], -1);
		else { S[len++] = ii(id[i], cnt); res = max(res, cnt); }
	}
	printf("%d\n", res);
	return 0;
}