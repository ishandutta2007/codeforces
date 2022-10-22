#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int q;
int a, b;
char str[Maxn];
int slen;
vector <int> seq;

bool Solve()
{
    if (seq.empty() || seq[0] < a) return false;
    if (seq.size() >= 2 && seq[int(seq.size()) - 2] >= 2 * b && seq.back() >= 2 * b) return false;
    if (seq.back() < 2 * b) return int(seq.size()) % 2 != 0;
    int len = seq.back(); seq.pop_back();
    for (int i = 0; i + a <= len; i++) {
        int fir = i, sec = len - (i + a);
        if (fir >= 2 * b || sec >= 2 * b) continue;
        int mn = Maxn;
        if (!seq.empty()) mn = min(mn, seq[0]);
        int siz = int(seq.size());
        if (fir >= b) { siz++; mn = min(mn, fir); }
        if (sec >= b) { siz++; mn = min(mn, sec); }
        if (mn >= a && siz % 2 == 0) return true;
    }
    return false;
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &a, &b);
        scanf("%s", str);
        slen = strlen(str);
        seq.clear();
        for (int i = 0; i < slen; )
            if (str[i] == 'X') i++;
            else {
                int j = i;
                while (j < slen && str[i] == str[j]) j++;
                if (j - i >= b)
                    seq.push_back(j - i);
                i = j;
            }
        sort(seq.begin(), seq.end());
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}