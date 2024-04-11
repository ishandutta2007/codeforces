#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3005;

int n, k;
char str[Maxn];
int R[Maxn];
int mn[Maxn];
int tot;
vector <int> res[Maxn * Maxn], oth[Maxn * Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str + 1);
    bool ch = true;
    int pnt = 0;
    while (ch) {
        ch = false;
        for (int i = 1; i < n; i++)
            if (str[i] == 'R' && str[i + 1] == 'L') {
                ch = true;
                res[pnt].push_back(i);
                swap(str[i], str[i + 1]);
                i++;
            }
        if (ch) pnt++;
    }
    if (pnt > k) { printf("-1\n"); return 0; }
    int pnt2 = 0;
    int nd = k - pnt;
    for (int i = 0; i < pnt; i++) {
        while (nd > 0 && res[i].size() > 1) {
            oth[pnt2++].push_back(res[i].back()); res[i].pop_back();
            nd--;
        }
        oth[pnt2++] = res[i];
    }
    if (pnt2 < k) { printf("-1\n"); return 0; }
    for (int i = 0; i < pnt2; i++) {
        printf("%d", int(oth[i].size()));
        for (int j = 0; j < oth[i].size(); j++)
            printf(" %d", oth[i][j]);
        printf("\n");
    }
    return 0;
}