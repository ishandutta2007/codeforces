#include <cstdio>
#include <algorithm>
#define mp make_pair
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
ii a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first); a[i].second = i + 1;
    }
    sort(a, a + n);
    printf("%d\n", n - (n / 2));
    for (int i = 0; i < n; i += 2) printf("%d%c", a[i].second, i + 2 < n? ' ': '\n');
    printf("%d\n", n / 2);
    for (int i = 1; i < n; i += 2) printf("%d%c", a[i].second, i + 2 < n? ' ': '\n');
    return 0;
}