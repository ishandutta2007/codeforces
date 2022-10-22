#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int k;

ll Random(ll l, ll r)
{
    int siz = r - l + 1;
    int pw = 0;
    while ((1 << pw) < siz) pw++;
    while (true) {
        int cand = rand() % (1 << pw);
        if (cand < siz) return l + cand;
    }
    return -1; // can't happen
}

bool Ask(ll lef, ll rig)
{
    printf("%I64d %I64d\n", lef, rig); fflush(stdout);
    string s; cin >> s;
    return s == "Yes";
}

void Compress(ll &lef, ll &rig)
{
    while (lef + 46 <= rig) {
        ll mid = lef + rig >> 1ll;
        if (Ask(lef, mid)) {
            lef = max(1ll, lef - k);
            rig = min(ll(n), mid + k);
        } else {
            lef = max(1ll, mid + 1ll - k);
            rig = min(ll(n), rig + k);
        }
    }
}

int main()
{
    srand(time(0));
    scanf("%I64d %d", &n, &k);
    ll lef = 1, rig = n;
    Compress(lef, rig);
    while (true) {
        ll guess = Random(lef, rig);
        if (Ask(guess, guess)) break;
        lef = max(1ll, lef - k);
        rig = min(ll(n), rig + k);
        Compress(lef, rig);
    }
    return 0;
}