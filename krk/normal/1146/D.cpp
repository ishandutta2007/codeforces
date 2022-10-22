#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 200005;

int m, a, b;
int lim;
bool tk[Maxm];
vector <int> seq;
ll res;

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

int main()
{
    scanf("%d %d %d", &m, &a, &b);
    tk[0] = true;
    int pnt = 0;
    for (lim = 0; lim <= m && lim < Maxm; lim++) {
        if (tk[lim]) seq.push_back(lim);
        while (pnt < seq.size()) {
            int v = seq[pnt++];
            if (v + a < Maxm && !tk[v + a]) {
                tk[v + a] = true;
                if (v + a <= lim) seq.push_back(v + a);
            }
            if (v - b >= 0 && !tk[v - b]) {
                tk[v - b] = true;
                seq.push_back(v - b);
            }
        }
        res += int(seq.size());
    }
    int g = gcd(a, b);
    int l = Maxm, r = m;
    while (l <= r)
        if (l % g != 0) { res += l / g + 1; l++; }
        else if (r % g != g - 1) { res += r / g + 1; r--; }
        else {
            int fir = l / g + 1;
            int lst = r / g + 1;
            ll my = ll(fir + lst) * (lst - fir + 1) / 2ll;
            res += ll(g) * my;
            break;
        }
    cout << res << endl;
    return 0;
}