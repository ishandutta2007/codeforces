#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;
const int Inf = 1000000000;

int T;
int n;
int p[Maxn], inp[Maxn];
vector <vector <int> > B;
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        B.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            inp[p[i]] = i;
            B.push_back({i, p[i]});
        }
        while (B.size() > 1) {
            int mn = Inf;
            ii wth = ii(-1, -1);
            for (int i = 0; i < B.size(); i++)
                for (int j = 0; j < B[i].size(); j++)
                    if (B[i][j] < mn) {
                        mn = B[i][j];
                        wth = ii(i, j);
                    }
            mn = Inf;
            ii oth = ii(-1, -1);
            for (int i = 0; i < B.size(); i++) if (wth.first != i) {
                int cand = abs(B[wth.first][wth.second] - B[i][1 - wth.second]);
                if (cand < mn) {
                    mn = cand;
                    oth = ii(i, 1 - wth.second);
                }
            }
            if (wth.second == 1) swap(wth, oth);
           // printf("join %d, %d wth %d, %d\n", B[wth.first][0], B[wth.first][1], B[oth.first][0], B[oth.first][1]);
            res[B[wth.first][wth.second]] = inp[B[oth.first][oth.second]];
            B[wth.first][0] = B[oth.first][0];
            B.erase(B.begin() + oth.first);
        }
        res[B[0][0]] = inp[B[0][1]];
        int num = 1;
        do {
            printf("%d%c", num, res[num] == 1? '\n': ' ');
            num = res[num];
        } while (num != 1);
    }
    return 0;
}