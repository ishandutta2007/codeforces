#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int ones = 0;
        for (int i = 0; i < n; i++)
            ones += str[i] == '1';
        if (ones == 0 || ones % 2) { printf("NO\n"); continue; }
        printf("YES\n");
        vector <ii> seq;
        for (int i = 0; i < n; i++) {
            ii cur = ii(i + 1, str[i] - '0');
            while (!seq.empty() && seq.back().second != cur.second) {
                ii p = seq.back(); seq.pop_back();
                printf("%d %d\n", p.first, cur.first);
                if (p.second == 0) cur.first = p.first;
                cur.second = 1;
            }
            seq.push_back(cur);
        }
        for (int i = 1; i < seq.size(); i++)
            printf("%d %d\n", seq[0].first, seq[i].first);
    }
    return 0;
}