#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;

int T;
int n;
int b[Maxn];
vector <ii> add[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            add[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            int lef = 1, rig = n;
            while (lef <= rig) {
                int mid = lef + rig >> 1;
                if (i / mid > b[i]) lef = mid + 1;
                else rig = mid - 1;
            }
            int L = lef;
            lef = 1, rig = n;
            while (lef <= rig) {
                int mid = lef + rig >> 1;
                if (i / mid < b[i]) rig = mid - 1;
                else lef = mid + 1;
            }
            int R = rig;
            add[L].push_back(ii(-R, i));
        }
        priority_queue <ii> Q;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < add[i].size(); j++)
                Q.push(add[i][j]);
            res[Q.top().second] = i; Q.pop();
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}