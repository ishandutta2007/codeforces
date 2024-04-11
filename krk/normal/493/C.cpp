#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000000;

int n;
int a[Maxn];
int m;
int b[Maxn];
vector <int> un;
int res1 = -Inf, res2 = Inf;

int main()
{
    un.push_back(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); un.push_back(a[i]);
    }
    sort(a, a + n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]); un.push_back(b[i]);
    }
    sort(b, b + m);
    for (int i = 0; i < un.size(); i++) {
        int ind1 = upper_bound(a, a + n, un[i]) - a;
        int has1 = ind1 * 2 + (n - ind1) * 3;
        int ind2 = upper_bound(b, b + m, un[i]) - b;
        int has2 = ind2 * 2 + (m - ind2) * 3;
        if (has1 - has2 > res1 - res2 || has1 - has2 == res1 - res2 && has1 > res1) {
            res1 = has1; res2 = has2;
        }
    }
    printf("%d:%d\n", res1, res2);
    return 0;
}