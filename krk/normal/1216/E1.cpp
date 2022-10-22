#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 18;

ll me[Maxd];
ll pw[Maxd], pw10[Maxd];
ll plen[Maxd];
int q;
ll k;

int Solve(ll k)
{
    int pnt = 1;
    while (me[pnt] < k) {
        k -= me[pnt];
        pnt++;
    }
    vector <int> seq;
    ll st = plen[pnt];
    for (int i = pnt - 1; i >= 0; i--)
        for (int j = i == pnt - 1? 1: 0; j < 10; j++) {
            ll sub = pw10[i] * st + pw10[i] * (pw10[i] + 1) / 2 * pnt;
            if (sub < k) { k -= sub; st += pw10[i] * pnt; }
            else { seq.push_back(j); break; }
        }
    int p = 0;
    for (int i = 1; ; i++) {
        if (i == pw10[p]) p++;
        if (p < k) k -= p;
        else {
            stringstream ss; ss << i;
            string s; ss >> s;
            return s[k - 1] - '0';
        }
    }
    return -1;
}

int main()
{
    ll res = 0;
    pw[1] = 9;
    for (int i = 2; i < Maxd; i++)
        pw[i] = pw[i - 1] * 10;
    ll len = 0;
    for (int i = 1; i < 10; i++) {
        plen[i] = len;
        me[i] = pw[i] * len + pw[i] * (pw[i] + 1) / 2 * i;
        len += pw[i] * i;
    }
    pw10[0] = 1;
    for (int i = 1; i < Maxd; i++)
        pw10[i] = pw10[i - 1] * 10;
    scanf("%d", &q);
    while (q--) {
        scanf("%I64d", &k);
        printf("%d\n", Solve(k));
    }
    return 0;
}