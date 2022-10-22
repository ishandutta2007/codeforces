#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

bool spec[Maxl];
int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        fill(spec, spec + Maxl, false);
        int cnt; scanf("%d", &cnt);
        while (cnt--) {
            char ch; scanf(" %c", &ch);
            spec[ch - 'a'] = true;
        }
        vector <int> seq;
        int cur = 0;
        for (int i = 0; i < n; i++)
            if (spec[str[i] - 'a']) {
                seq.push_back(cur);
                cur = 0;
            } else cur++;
        int res = 0;
        if (!seq.empty()) {
            int i = 0;
            for (int j = 1; j < seq.size(); j++)
                if (seq[j] >= seq[i]) i = j;
            res = seq[i] + (i > 0);
        }
        printf("%d\n", res);
    }
    return 0;
}