#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 10000000;

int n, m;
int s;
ll t;
ii seq[Maxm];
int slen;

int main()
{
    cin >> n >> m;
    cin >> s >> t;
    s--;
    ll tims = 0;
    while (t > 0 && slen < Maxm) {
        seq[slen++] = ii(s, t % n);
        if (s < m) s = (s + t) % n;
        else s = (s - t % n + n) % n;
        t--;
    }
    if (t > 0) {
        for (int i = slen - 2; i >= 0; i--)
            if (seq[i] == seq[slen - 1]) {
                t %= (slen - 1 - i);
                break;
            }
    }
    while (t > 0) {
        if (s < m) s = (s + t) % n;
        else s = (s - t % n + n) % n;
        t--;
    }
    cout << s + 1 << endl;
    return 0;
}