#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
char str[Maxn];
vector <int> V[3];
int pnt[3];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int n = strlen(str);
        for (int i = 0; i < 3; i++)
            V[i].clear();
        for (int i = 0; i < n; i++)
            V[str[i] - '1'].push_back(i);
        deque <ii> D;
        for (int i = 0; i < 3; i++) {
            V[i].push_back(n);
            pnt[i] = 0;
            D.push_back(ii(V[i][0], i));
        }
        sort(D.begin(), D.end());
        int res = Maxn;
        while (D.back().first < n) {
            res = min(res, D.back().first - D.front().first + 1);
            int ind = D.front().second;
            D.pop_front();
            D.push_back(ii(V[ind][++pnt[ind]], ind));
            sort(D.begin(), D.end());
        }
        printf("%d\n", res < Maxn? res: 0);
    }
    return 0;
}