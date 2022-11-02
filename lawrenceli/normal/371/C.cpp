#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;

string str;
int nb, ns, nc, pb, ps, pc, fb, fs, fc;
ll r;

bool pos(ll mid) {
    ll b = mid * fb, s = mid * fs, c = mid * fc;
    ll sum = max(b - nb, ll(0)) * pb + max(s - ns, ll(0)) * ps + max(c - nc, ll(0)) * pc;
    return sum <= r;
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> str >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    for (int i=0; i<str.length(); i++) {
        if (str[i] == 'B') fb++;
        else if (str[i] == 'S') fs++;
        else fc++;
    }

    ll lo = 0, hi = 1e13;
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (pos(mid)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << endl;
    return 0;
}