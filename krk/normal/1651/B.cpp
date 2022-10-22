#include <bits/stdc++.h>
using namespace std;

vector <int> seq;

int main()
{
    seq.push_back(1);
    while (seq.back() <= 1000000000 / 3) {
        int nw = seq.back() * 3;
        seq.push_back(nw);
    }
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        if (n <= seq.size()) {
            printf("YES\n");
            for (int i = 0; i < n; i++)
                printf("%d%c", seq[i], i + 1 < n? ' ': '\n');
        } else printf("NO\n");
    }
    return 0;
}