#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <ios>
#include <cassert>
#include <iomanip>
#include <cmath>

using namespace std;

#define A first
#define B second

typedef long double ld;
typedef pair<ld, int> pdi;

const int maxn = 200100;

int n, t, Q;
int p[maxn], l[maxn], q[maxn]; //q - number of Johnny's tickets

set<pdi> S, T; //S - last update for each raffle, T - next update for each raffle

int cnt;
ld tot;

ld exp(int i, int j) { return ld(p[i]) * j / (l[i] + j); }

ld diff(int i, int j) { return exp(i, j + 1) - exp(i, j); }

pdi newp(int i, int j) { return pdi(diff(i, j), i); }

void addt() {
    while (cnt < t && !S.empty()) {
        int i = S.rbegin()->B;
        if (q[i]) T.erase(newp(i, q[i] - 1)); //wtf!!!
        T.insert(newp(i, q[i]));
        S.erase(newp(i, q[i]));
        tot += diff(i, q[i]);
        q[i]++, cnt++;
        if (q[i] < l[i]) S.insert(newp(i, q[i]));
    }
}

void reml() {
    if (!T.empty()) {
        int j = T.begin()->B;
        if (q[j] < l[j]) S.erase(newp(j, q[j]));
        T.erase(newp(j, q[j] - 1));
        tot -= diff(j, q[j] - 1);
        q[j]--, cnt--;
        if (q[j]) T.insert(newp(j, q[j] - 1));
        S.insert(newp(j, q[j]));
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> t >> Q;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++)
        S.insert(newp(i, 0));

    addt();

    cout << fixed << setprecision(10);

    for (int i = 0; i < Q; i++) {
        int type, r;
        cin >> type >> r;
        r--;
        if (type == 1) {
            tot -= exp(r, q[r]);
            if (q[r]) T.erase(newp(r, q[r] - 1));
            if (q[r] < l[r]) S.erase(newp(r, q[r]));
            l[r]++;

            if (q[r]) q[r]--, cnt--;
            tot += exp(r, q[r]);
            if (q[r]) T.insert(newp(r, q[r] - 1));
            S.insert(newp(r, q[r]));

            reml();
            addt();

            cout << tot << '\n';
        } else {
            tot -= exp(r, q[r]);
            if (q[r]) T.erase(newp(r, q[r] - 1));
            if (q[r] < l[r]) S.erase(newp(r, q[r]));
            l[r]--;

            if (q[r]) q[r]--, cnt--;
            tot += exp(r, q[r]);
            if (q[r]) T.insert(newp(r, q[r] - 1));
            if (q[r] < l[r]) S.insert(newp(r, q[r]));

            reml();
            addt();
            
            cout << tot << '\n';
        }
    }
}