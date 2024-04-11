#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 55;

int n, k;
ii P[Maxn];
int res;

bool Less(const ii &a, const ii &b)
{
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d %d", &P[i].first, &P[i].second);
    sort(P, P + n, Less);
    for (int i = 0; i < n; i++) res += P[i] == P[k - 1];
    printf("%d\n", res);
    return 0;
}