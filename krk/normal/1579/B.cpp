#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 52;

int T;
int n;
int a[Maxn];
vector <iii> res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        res.clear();
        for (int i = 0; i < n; i++) {
            int b = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[b]) b = j;
            if (b != i) {
                res.push_back(iii(ii(i, b), b - i));
                int cur = a[b];
                for (int j = i; j <= b; j++)
                    swap(a[j], cur);
            }
        }
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d %d %d\n", res[i].first.first + 1, res[i].first.second + 1, res[i].second);
    }
    return 0;
}