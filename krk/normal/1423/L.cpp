#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Maxk = 15;

int n, s, d;
bool my[Maxn][Maxn];
int mask[Maxn];
int imp[Maxn];
vector <int> good, bad;
int ingood[Maxn];
vector <int> V;
int dp[11][1 << 20];
bool cur[Maxn];

int Gen(int lvl, int mymask)
{
    if (lvl >= bad.size()) return __builtin_popcount(mymask);
    return min(Gen(lvl + 1, mymask), Gen(lvl + 1, mymask ^ V[lvl]));
}

int main()
{
    scanf("%d %d %d", &n, &s, &d);
    for (int i = 0; i < s; i++) {
        int cnt; scanf("%d", &cnt);
        while (cnt--) {
            int num; scanf("%d", &num);
            my[i][num] = true;
        }
        int mymask = 1 << i;
        bool inimp = false;
        for (int j = 1; j <= n; j++) if (my[i][j])
            if (mask[j]) {
                mymask ^= mask[j];
                for (int l = j; l <= n; l++)
                    my[i][l] ^= my[imp[j]][l];
            } else {
                mask[j] = mymask;
                imp[j] = i;
                inimp = true;
                break;
            }
        if (inimp) {
            ingood[i] = good.size();
            good.push_back(i);
        } else {
            ingood[i] = -1;
            bad.push_back(i);
            V.push_back(mymask);
        }
    }
    if (good.size() <= 20) {
        fill((int*)dp, (int*)dp + 11 * (1 << 20), Maxn);
        for (int j = 0; j < 1 << int(good.size()); j++)
            dp[0][j] = __builtin_popcount(j);
        for (int i = 0; i < bad.size(); i++) {
            int goodmask = 0;
            for (int j = 0; j < s; j++) if (ingood[j] != -1 && bool(V[i] & 1 << j))
                goodmask |= 1 << ingood[j];
            for (int j = 0; j < 1 << int(good.size()); j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j ^ goodmask] + 1);
            }
        }
    }
    for (int i = 1; i <= d; i++) {
        fill(cur, cur + Maxn, false);
        int cnt; scanf("%d", &cnt);
        while (cnt--) {
            int num; scanf("%d", &num);
            cur[num] = true;
        }
        int mymask = 0;
        bool fall = false;
        for (int j = 1; j <= n; j++) if (cur[j])
            if (mask[j]) {
                mymask ^= mask[j];
                for (int l = j; l <= n; l++)
                    cur[l] ^= my[imp[j]][l];
            } else {
                fall = true;
                break;
            }
        if (fall) {
            printf("-1\n");
            continue;
        }
        if (good.size() <= 20) {
            int goodmask = 0;
            for (int j = 0; j < s; j++) if (ingood[j] != -1 && bool(mymask & 1 << j))
                goodmask |= 1 << ingood[j];
            printf("%d\n", dp[bad.size()][goodmask]);
        } else printf("%d\n", Gen(0, mymask));
    }
    return 0;
}