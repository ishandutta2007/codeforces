#include <cstdio>
#include <vector>
using namespace std;

int n, m, k;
vector <int> res;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    if (k == 1)
        for (int i = 1; i <= m + n; i += n - 1) res.push_back(i);
    else {
        for (int i = 0; i < k; i++) res.push_back(1);
        res.push_back(n);
        int l = 1;
        while (res[l] + n <= m + n) res.push_back(res[l++] + n);
    }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++) printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}