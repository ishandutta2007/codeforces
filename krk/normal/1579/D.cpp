#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
vector <ii> res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        res.clear();
        priority_queue <ii> Q;
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            if (a > 0) Q.push(ii(a, i));
        }
        while (!Q.empty()) {
            ii v = Q.top(); Q.pop();
            if (Q.empty()) break;
            ii u = Q.top(); Q.pop();
            res.push_back(ii(v.second, u.second));
            if (--v.first > 0) Q.push(v);
            if (--u.first > 0) Q.push(u);
        }
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}