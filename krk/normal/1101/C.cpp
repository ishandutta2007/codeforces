#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

int t;
int n;
iii seq[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &seq[i].first.first, &seq[i].first.second);
            seq[i].second = i;
        }
        sort(seq, seq + n);
        int rig = seq[0].first.second;
        int fin = -1;
        for (int i = 1; i < n; i++)
            if (rig < seq[i].first.first) { fin = i; break; }
            else rig = max(rig, seq[i].first.second);
        if (fin == -1) printf("-1\n");
        else {
            for (int i = 0; i < n; i++)
                res[seq[i].second] = (i >= fin) + 1;
            for (int i = 0; i < n; i++)
                printf("%d%c", res[i], i + 1 < n? ' ': '\n');
        }
    }
    return 0;
}