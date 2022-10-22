#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100;

int s, k;
int f[Maxn];
vector <int> res;

int main()
{
    scanf("%d %d", &s, &k);
    f[0] = 1;
    int i;
    for (i = 1; i < Maxn; i++) {
        for (int j = max(0, i - k); j < i && f[i] <= s; j++) f[i] += f[j];
        if (f[i] > s) break;
    }
    for (i--; i >= 0; i--)
        while (f[i] <= s) {
            res.push_back(f[i]); s -= f[i];
        }
    if (res.size() < 2) res.push_back(0);
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++) printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}