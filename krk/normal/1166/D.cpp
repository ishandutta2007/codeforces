#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 55;

int q;
ll a, b, m;
llll V[Maxn];
int vlen;
ll R[Maxn];

int Check(llll sum, int ind, ll val)
{
    llll cur = llll(val, val);
    sum.first += cur.first; sum.second += cur.second;
    for (int i = ind + 1; i < vlen; i++) {
        cur = llll(sum.first + 1, sum.second + m);
        sum.first += cur.first; sum.second += cur.second;
    }
    if (b < cur.first) return -1;
    else if (b > cur.second) return 1;
    else return 0;
}

void Solve()
{
    vlen = 0;
    V[vlen++] = llll(a, a);
    while (true)
        if (V[vlen - 1].second < b) {
            ll mn = 0, mx = 0;
            for (int i = 0; i < vlen; i++) {
                mn += V[i].first;
                mx += V[i].second;
            }
            mn++; mx += m;
            V[vlen++] = llll(mn, mx);
        } else if (b < V[vlen - 1].first) { printf("-1\n"); return; }
        else break;
    llll sum = llll(0, 0);
    llll cur = llll(a, a);
    for (int i = 0; i < vlen; i++) {
        ll lef = cur.first, rig = cur.second;
        while (lef <= rig) {
            ll mid = lef + rig >> 1;
            int st = Check(sum, i, mid);
            if (st == 1) lef = mid + 1;
            else if (st == -1) rig = mid - 1;
            else {
                R[i] = mid;
                sum.first += mid; sum.second += mid;
                cur.first = sum.first + 1; cur.second = sum.second + m;
                break;
            }
        }
    }
    printf("%d ", vlen);
    for (int i = 0; i < vlen; i++)
        printf("%I64d%c", R[i], i + 1 < vlen? ' ': '\n');
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%I64d %I64d %I64d", &a, &b, &m);
        Solve();
    }
    return 0;
}