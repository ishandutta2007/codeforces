#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll L[Maxn];
char typ[Maxn];
ll cur;
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &L[i]);
        res += L[i];
    }
    scanf("%s", typ);
    cur = 0;
    bool wasW = false;
    ll hasW = 0, hasG = 0;
    for (int i = 0; i < n; i++) {
        cur -= L[i];
        if (typ[i] == 'G') hasG += 2 * L[i];
        else if (typ[i] == 'W') { hasW += 2 * L[i]; wasW = true; }
        // Water
        ll tk = min(-cur, hasW);
        cur += tk; hasW -= tk;
        res += tk;
        // Grass
        tk = min(-cur, hasG);
        cur += tk; hasG -= tk;
        res += 2 * tk;
        // Water/Grass
        if (wasW) res += 3 * (-cur);
        else res += 5 * (-cur);
        cur = 0;
    }
    cout << res << endl;
    return 0;
}