#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 100005;

int n, m, x, y;
int a[Maxn], b[Maxn], pa, pb;
vector <int> res1, res2;

int main()
{
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    pa = pb = 1;
    while (pa <= n && pb <= m)
        if (a[pa] + y < b[pb]) pa++;
        else if (b[pb] < a[pa] - x) pb++;
        else {
            res1.push_back(pa++); res2.push_back(pb++);
        }
    printf("%d\n", res1.size());
    for (int i = 0; i < res1.size(); i++) printf("%d %d\n", res1[i], res2[i]);
    return 0;
}