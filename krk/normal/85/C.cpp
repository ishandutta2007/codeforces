#include <iostream>
#include <iomanip>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int st;
int p[Maxn], val[Maxn];
int l[Maxn], r[Maxn];
int sval[Maxn], bval[Maxn];
int k;
pair <int, int> srt[Maxn];
double res[Maxn];

void DP(int v)
{
     if (!l[v]) sval[v] = bval[v] = val[v];
     else {
          DP(l[v]); DP(r[v]);
          sval[v] = sval[l[v]]; bval[v] = bval[r[v]];
     }
}

void Count(int v, int lw, int hg, ll sum, ll hm)
{
     if (!l[v]) {
                int from = upper_bound(srt, srt + k, make_pair(lw, 0)) - srt;
                int to = upper_bound(srt, srt + k, make_pair(hg, 0)) - srt;
                double curres = double(sum) / double(hm);
                for (int i = from; i < to; i++)
                   res[srt[i].second] = curres;
     } else {
            Count(l[v], lw, val[v], sum + ll(sval[r[v]]), hm + 1LL);
            Count(r[v], val[v], hg, sum + ll(bval[l[v]]), hm + 1LL);
     }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
       cin >> p[i] >> val[i];
    for (int i = 1; i <= n; i++)
       if (p[i] == -1) st = i;
       else if (val[i] < val[p[i]]) l[p[i]] = i;
       else r[p[i]] = i;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> srt[i].first;
        srt[i].second = i;
    }
    sort(srt, srt + k);
    DP(st);
    Count(st, 0, 1000000001, 0LL, 0LL);
    for (int i = 0; i < k; i++)
       cout << fixed << setprecision(10) << res[i] << endl;
    return 0;
}