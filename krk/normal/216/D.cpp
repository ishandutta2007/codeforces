#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n;
vector <int> sec[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int cnt; scanf("%d", &cnt);
        while (cnt--) {
            int s; scanf("%d", &s);
            sec[i].push_back(s);
        }
        sort(sec[i].begin(), sec[i].end());
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j + 1 < sec[i].size(); j++) {
            int lind = (i + n - 1) % n, rind = (i + 1) % n;
            int l = upper_bound(sec[lind].begin(), sec[lind].end(), sec[i][j + 1]) -
                    upper_bound(sec[lind].begin(), sec[lind].end(), sec[i][j]);
            int r = upper_bound(sec[rind].begin(), sec[rind].end(), sec[i][j + 1]) -
                    upper_bound(sec[rind].begin(), sec[rind].end(), sec[i][j]);
            res += l != r;
        }
    printf("%d\n", res);
    return 0;
}