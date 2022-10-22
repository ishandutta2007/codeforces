#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;
vector <int> seq;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        seq.clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                seq.push_back(max(i, n - 1 - i) + max(j, m - 1 - j));
        sort(seq.begin(), seq.end());
        for (int i = 0; i < seq.size(); i++)
            printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    }
    return 0;
}