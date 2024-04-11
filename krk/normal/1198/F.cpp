#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
vector <int> un;
vector <int> has[Maxn];
bool res[Maxn];
int seq[Maxn], slen;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

bool Solve(int lvl, int A, int B)
{
    if (A == 1 && B == 1) return true;
    if (lvl >= slen) return false;
    bool help = false;
    if (A == 0 || a[seq[lvl]] % A) {
        help = true;
        res[seq[lvl]] = false;
        if (Solve(lvl + 1, gcd(A, a[seq[lvl]]), B))
            return true;
    }
    if (B == 0 || a[seq[lvl]] % B) {
        help = true;
        res[seq[lvl]] = true;
        if (Solve(lvl + 1, A, gcd(B, a[seq[lvl]])))
            return true;
    }
    if (!help) {
        if (Solve(lvl + 1, A, B))
            return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
        tot = gcd(tot, a[i]);
    }
    if (tot != 1) { printf("NO\n"); return 0; }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        has[ind].push_back(i);
    }
    int A = 0, B = 0;
    for (int i = 0; i < un.size(); i++)
        if (has[i].size() >= 2) {
            res[has[i][0]] = true;
            A = gcd(A, un[i]);
            B = gcd(B, un[i]);
            has[i].clear();
        } else if (!has[i].empty()) seq[slen++] = has[i][0];
    shuffle(seq, seq + slen, rng);
    if (Solve(1, gcd(A, a[seq[0]]), B)) {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i]? 2: 1, i + 1 < n? ' ': '\n');
    } else printf("NO\n");
    return 0;
}