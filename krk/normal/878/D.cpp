#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> ii;

const int Maxb = 64;
const int Maxk = 12;
const int Maxn = 100020;

int n, k, q;
int wh[Maxk][Maxn];
ii srt[Maxn][Maxk];
int qtyp[Maxn], qx[Maxn], qy[Maxn], qnew[Maxn];
bool mx[Maxn];
vector <int> un;
int m;
vector <vector <ull> > mask;

int main()
{
    scanf("%d %d %d", &n, &k, &q);
    int memk = k;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++) {
            int a; scanf("%d", &a);
            srt[j][i] = ii(a, i);
        }
    for (int i = 0; i < n; i++) {
        sort(srt[i], srt[i] + k);
        for (int j = 0; j < k; j++)
            wh[srt[i][j].second][i] = j;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &qtyp[i], &qx[i], &qy[i]);
        qx[i]--; qy[i]--;
        if (qtyp[i] == 3) {
            un.push_back(qy[i]);
            if (mx[qx[i]]) qnew[i] = 0;
            else qnew[i] = Maxk - 1;
        } else {
            qnew[i] = k++;
            mx[qnew[i]] = qtyp[i] == 1;
        }
    }
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < q; i++)
        if (qtyp[i] == 3)
            qy[i] = lower_bound(un.begin(), un.end(), qy[i]) - un.begin();
    m = int(un.size()) / Maxb;
    if (un.size() > Maxb * m) m++;
    if (m == 0) return 0;
    mask.resize(k);
    for (int i = 0; i < k; i++)
        mask[i].resize(m);
    for (int t = 1; t < Maxk; t++) {
        for (int i = 0; i < memk; i++)
            for (int j = 0; j < un.size(); j++) {
                int b = wh[i][un[j]] >= t;
                if (bool(mask[i][j / Maxb] & ull(1) << ull(j % Maxb)) != b)
                    mask[i][j / Maxb] ^= ull(1) << ull(j % Maxb);
            }
        for (int i = 0; i < q; i++)
            if (qtyp[i] == 3) {
                bool b = bool(mask[qx[i]][qy[i] / Maxb] & ull(1) << ull(qy[i] % Maxb));
                if (mx[qx[i]] && b) qnew[i] = t;
                else if (!mx[qx[i]] && !b && t - 1 <= qnew[i]) qnew[i] = t - 1;
            } else if (qtyp[i] == 1)
                for (int j = 0; j < m; j++)
                    mask[qnew[i]][j] = mask[qx[i]][j] | mask[qy[i]][j];
            else for (int j = 0; j < m; j++)
                    mask[qnew[i]][j] = mask[qx[i]][j] & mask[qy[i]][j];
    }
    for (int i = 0; i < q; i++)
        if (qtyp[i] == 3)
            printf("%d\n", srt[un[qy[i]]][qnew[i]].first);
    return 0;
}