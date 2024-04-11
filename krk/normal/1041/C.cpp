#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m, d;
ii seq[Maxn];
int res[Maxn];

bool Check(int x)
{
    for (int i = 0; i < n; i++) {
        res[seq[i].second] = i % x + 1;
        if (i >= x)
            if (seq[i].first - seq[i - x].first - 1 < d)
                return false;
    }
    return true;
}

int main()
{
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &seq[i].first);
        seq[i].second = i;
    }
    sort(seq, seq + n);
    int lef = 1, rig = n;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    rig++;
    Check(rig);
    printf("%d\n", rig);
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}