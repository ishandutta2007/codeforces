#include <bits/stdc++.h>
using namespace std;

const int Maxn = 11;

int T;
int n;
int a[Maxn];

bool Check(int lvl, int cur, int nd, const vector <int> &seq)
{
    if (lvl >= seq.size()) return cur == nd;
    else {
        if (Check(lvl + 1, cur, nd, seq)) return true;
        if (Check(lvl + 1, cur + seq[lvl], nd, seq)) return true;
        return Check(lvl + 1, cur - seq[lvl], nd, seq);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        bool res = false;
        for (int i = 0; i < n && !res; i++) {
            vector <int> seq;
            for (int j = 0; j < n; j++) if (i != j)
                seq.push_back(a[j]);
            res = Check(0, 0, a[i], seq);
        }
        printf("%s\n", res? "YES": "NO");
    }
    return 0;
}