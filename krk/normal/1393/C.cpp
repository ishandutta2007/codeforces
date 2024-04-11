#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n;
int has[Maxn];
vector <ii> seq;
vector <int> add[Maxn];

bool Check(int x)
{
    for (int i = 0; i < n; i++)
        add[i].clear();
    priority_queue <int> Q;
    for (int i = 0; i < seq.size(); i++)
        Q.push(seq[i].first);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < add[i].size(); j++)
            Q.push(add[i][j]);
        if (Q.empty()) return false;
        int got = Q.top(); Q.pop();
        got--;
        if (got > 0 && i + x < n)
            add[i + x].push_back(got);
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(has + 1, has + n + 1, 0);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            has[a]++;
        }
        seq.clear();
        for (int i = 1; i <= n; i++) if (has[i])
            seq.push_back(ii(has[i], i));
        sort(seq.rbegin(), seq.rend());
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (Check(mid)) l = mid + 1;
            else r = mid - 1;
        }
        printf("%d\n", r - 1);
    }
    return 0;
}