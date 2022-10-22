#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];
map <ii, int> M;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str + 1);
        M.clear();
        M[ii(0, 0)] = 0;
        ii p = ii(0, 0);
        int res = Maxn, bi, bj;
        for (int i = 1; i <= n; i++) {
            if (str[i] == 'L') p.first--;
            else if (str[i] == 'R') p.first++;
            else if (str[i] == 'U') p.second++;
            else p.second--;
            auto it = M.find(p);
            if (it != M.end()) {
                if (i - it->second < res) {
                    res = i - it->second;
                    bi = it->second + 1;
                    bj = i;
                }
                it->second = i;
            } else M.insert(make_pair(p, i));
        }
        if (res >= Maxn) printf("-1\n");
        else printf("%d %d\n", bi, bj);
    }
    return 0;
}