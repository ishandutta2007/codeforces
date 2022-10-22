#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 55;

int n;
int c[Maxn], nc[Maxn];
vector <vector <int> > res;

void Op(const vector <int> &D)
{
    res.push_back(D);
    int cur = n + 1;
    int pnt = 1;
    for (int i = 0; i < D.size(); i++) {
        cur -= D[i];
        for (int j = 0; j < D[i]; j++)
            nc[cur + j] = c[pnt++];
    }
    for (int i = 1; i <= n; i++)
        c[i] = nc[i];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    while (true) {
        vector <ii> ints;
        vector <int> D;
        for (int i = 1, j; i <= n; i = j) {
            j = i + 1;
            while (j <= n && c[j] == c[j - 1] + 1)
                j++;
            ints.push_back(ii(i, j - 1));
        }
        bool was = false;
        for (int i = 0; i < ints.size() && !was; i++)
            for (int j = i + 1; j < ints.size() && !was; j++)
                if (c[ints[i].first] == c[ints[j].second] + 1) {
                    was = true;
                    if (ints[i].first > 1) D.push_back(ints[i].first - 1);
                    D.push_back(ints[i].second - ints[i].first + 1);
                    D.push_back(ints[j].second - ints[i].second);
                    if (ints[j].second < n) D.push_back(n - ints[j].second);
                    Op(D);
                }
        if (!was) break;
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++) {
        printf("%d", int(res[i].size()));
        for (int j = 0; j < res[i].size(); j++)
            printf(" %d", res[i][j]);
        printf("\n");
    }
    return 0;
}