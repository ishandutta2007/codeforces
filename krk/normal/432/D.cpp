#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

char str[Maxn];
int slen;
int cnt[Maxn];
bool was[Maxn];
int Z[Maxn];
vector <ii> res;

int main()
{
	scanf("%s", str); slen = strlen(str);
	cnt[slen]++; was[slen] = true;
	int L = -1, R = -1;
	for (int i = 1; i < slen; i++) {
		if (i <= R) Z[i] = min(R - i + 1, Z[i - L]);
		while (i + Z[i] < slen && str[Z[i]] == str[i + Z[i]]) Z[i]++;
		if (i + Z[i] - 1 > R) { L = i; R = i + Z[i] - 1; }
		if (i + Z[i] == slen) was[Z[i]] = true;
		cnt[Z[i]]++;
	}
	for (int i = slen - 1; i >= 0; i--)
		cnt[i] += cnt[i + 1];
	for (int i = 1; i <= slen; i++) if (was[i])
		res.push_back(ii(i, cnt[i]));
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}