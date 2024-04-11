#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n, m;
ii H[Maxn];
int a[Maxn];
vector <int> res;

void insertLeft(int lef, ii me)
{
    res.push_back(me.second);
    for (int i = lef; i > 0; i--)
        if (H[i].first >= 0) {
            res.push_back(H[i].second);
            H[i] = ii(-1, -1);
        }
}

void insertRight(int rig, ii me)
{
    res.push_back(me.second);
    for (int i = rig; i <= n; i++)
        if (H[i].first >= 0) {
            res.push_back(H[i].second);
            H[i] = ii(-1, -1);
        }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        H[i] = ii(-1, -1);
    for (int i = 1; i <= m; i++) {
        int s, h; scanf("%d %d", &s, &h);
        H[s] = ii(h, i);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int lef = 1;
    while (H[lef].first < 0) lef++;
    int rig = n;
    while (H[rig].first < 0) rig--;
    ii my = H[lef]; H[lef] = ii(-1, -1);
    bool ins = false;
    while (lef < rig) {
        if (my.first + a[lef + 1] >= 0) {
            my.first += a[lef + 1]; a[lef + 1] = 0;
            lef++;
            if (my.first < H[lef].first) swap(my, H[lef]);
        } else {
            insertLeft(lef, my);
            ins = true;
            break;
        }
    }
    if (!ins) insertLeft(lef, my);
    if (lef < rig) {
        my = H[rig]; H[rig] = ii(-1, -1);
        ins = false;
        while (lef < rig) {
            if (my.first + a[rig - 1] >= 0) {
                my.first += a[rig - 1]; a[rig - 1] = 0;
                rig--;
                if (my.first < H[rig].first) swap(my, H[rig]);
            } else {
                insertRight(rig, my);
                ins = true;
                break;
            }
        }
        if (!ins) insertRight(rig, my);
    }
    if (lef < rig) printf("-1\n");
    else {
        printf("%d\n", lef);
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}