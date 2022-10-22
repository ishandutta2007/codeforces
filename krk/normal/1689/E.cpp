#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int Maxb = 32;

int T;
int n;
int a[Maxn];
int seq[Maxb], slen;
int res;

void Erase(int ind)
{
    for (int i = ind; i + 1 < slen; i++)
        seq[i] = seq[i + 1];
    slen--;
}

void Add(int mask)
{
    bool add = true;
    bool rep = true;
    while (rep) {
        rep = false;
        for (int i = slen - 1; i >= 0; i--)
            if (seq[i] & mask) {
                int got = (seq[i] | mask);
                if (got == seq[i]) { add = false; break; }
                mask = got;
                rep = true;
                Erase(i);
                break;
            }
    }
    if (add) seq[slen++] = mask;
}

bool Connected()
{
    slen = 0;
    for (int i = 0; i < n; i++)
        Add(a[i]);
    return slen == 1;
}

void Print()
{
    printf("%d\n", res);
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], i + 1 < n? ' ': '\n');
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == 0) { a[i]++; res++; }
        }
        if (Connected()) {
            Print();
            continue;
        }
        bool found = false;
        for (int i = 0; i < n && !found; i++)
            if (a[i] > 1) {
                a[i]--;
                if (Connected()) {
                    res++;
                    Print();
                    found = true;
                }
                a[i]++;
            }
        if (found) continue;
        vector <int> seq;
        int best = -1;
        for (int i = 0; i < n; i++) {
            int b = 0;
            while (!(a[i] & 1 << b)) b++;
            if (b > best) { best = b; seq.clear(); }
            if (b == best) seq.push_back(i);
        }
        res++; a[seq[0]]++;
        if (Connected()) {
            Print();
            continue;
        }
        res++; a[seq[1]]--;
        Print();
    }
    return 0;
}