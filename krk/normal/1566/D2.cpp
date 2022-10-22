#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;

int T;
int n, m;
int a[Maxn * Maxn];
map <int, deque <int> > M;
int B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        M.clear();
        for (int i = 0; i < n * m; i++) {
            scanf("%d", &a[i]);
            M[a[i]].push_back(i);
        }
        auto it = M.begin();
        for (int i = 0; i < n; i++) {
            int r = 0;
            while (r < m) {
                while (it->second.empty()) it++;
                int tk = min(int(it->second.size()), m - r);
                for (int j = 0; j < tk; j++)
                    B[i][r + tk - 1 - j] = it->second[j];
                r += tk;
                while (tk--)
                    it->second.pop_front();
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int j2 = j + 1; j2 < m; j2++)
                    res += B[i][j] < B[i][j2];
        printf("%d\n", res);
    }
    return 0;
}