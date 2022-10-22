#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int q;
int n;
int p[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; i++) if (p[i]) {
            vector <int> seq;
            int num = i;
            while (p[num]) {
                seq.push_back(num);
                int nxt = p[num]; p[num] = 0;
                num = nxt;
            }
            for (int j = 0; j < seq.size(); j++)
                res[seq[j]] = int(seq.size());
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}