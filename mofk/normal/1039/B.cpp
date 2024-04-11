#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long l, r;

bool ask(long long lo, long long hi) {
    cout << lo << ' ' << hi << endl;
    string s;
    cin >> s;
    if (s == "Bad") exit(0);
    return s == "Yes";
}

long long random(long long lo, long long hi) {
    long long ret = 0;
    for (int i = 0; i < 60; i += 15) ret |= (1LL * (rand() & 32767)) << i;
    return ret % (hi - lo + 1) + lo;
}

int main(void) {
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    l = 1, r = n;
    while (true) {
        if (r - l > 100) {
            long long m = l + r >> 1;
            bool res = ask(l, m);
            if (res) {
                l = max(1LL, l - k);
                r = min(n, m + k);
            }
            else {
                l = max(1LL, m + 1 - k);
                r = min(n, r + k);
            }
        }
        else {
            long long m = random(l, r);
            bool res = ask(m, m);
            if (res) return 0;
            else {
                l = max(1LL, l - k);
                r = min(n, r + k);
            }
        }
    }
    return 0;
}