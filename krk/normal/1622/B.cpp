#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
int p[Maxn];
char str[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <ii> seq[2];
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        scanf("%s", str);
        for (int i = 0; i < n; i++)
            seq[str[i] - '0'].push_back(ii(p[i], i));
        int pnt = 1;
        for (int i = 0; i < 2; i++) {
            sort(seq[i].begin(), seq[i].end());
            for (int j = 0; j < seq[i].size(); j++)
                res[seq[i][j].second] = pnt++;
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}