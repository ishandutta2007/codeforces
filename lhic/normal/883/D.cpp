#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const int MAXN = 2000001;

int nextPac[MAXN];
int nextStar[MAXN];
bool f[MAXN];
int n;
int md;

void pacor(int l, int r) {
    r = min(n, r);
    int pc = nextPac[l + 1];
    f[min(pc, r)] = true;
}

int main() {
#ifdef PAUNSVOKNO
    freopen("in", "r", stdin); cout.tie(nullptr);
    cout.setf(ios::fixed); cout.precision(20); ios_base::sync_with_stdio(false);
#endif

    cin >> n;
    string s;
    cin >> s;

    int stars = 0;
    int pacs = 0;

    for (int i = 0; i < n; i++) {
        stars += s[i] == '*';
        pacs += s[i] == 'P';
    }

    nextPac[n] = nextStar[n] = n;
    for (int i = n - 1; i >= 0; --i) {
        nextPac[i] = s[i] == 'P' ? i : nextPac[i + 1];
        nextStar[i] = s[i] == '*' ? i : nextStar[i + 1];
    }

    if (pacs == 1) {
        int pac = nextPac[0];
        pair <int, int> vl = {0, 0}, vr = {0, 0};
        {
            for (int i = pac - 1; i >= 0; --i) {
                if (s[i] == '*') {
                    vl.first++;
                    vl.second = i - pac;
                }
            }
        }

        {
            for (int i = pac + 1; i < n; ++i) {
                if (s[i] == '*') {
                    vr.first++;
                    vr.second = pac - i;
                }
            }
        }

        vl = max(vl, vr);

        cout << vl.first << " " << -vl.second << "\n";
        return 0;
    }

    int lg = 0, rg = MAXN;
    while (lg < rg) {
        md = (lg + rg) / 2;
        fill(begin(f), end(f), false);
        f[0] = true;

        for (int i = 0; i < n; i++) {
            if (!f[i]) {
                continue;
            }

            if (s[i] == 'P') {
                pacor(i, i + md + 1);
                continue;
            }

            if (s[i] == '.') {
                f[i + 1] = true;
                continue;
            }

            int pac1 = nextPac[i];
            if (pac1 == n || i + md < pac1) {
                continue;
            }

            f[pac1 + 1] = true;

            int pac2 = nextPac[pac1 + 1];

            if (pac2 == n || i + md < pac2) {
                continue;
            }

            pacor(pac2, pac1 + md + 1);

        }

        if (f[n]) {
            rg = md;
        } else {
            lg = md + 1;
        }
    }

    cout << stars << " " << lg << "\n";

}