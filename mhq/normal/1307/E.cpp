#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 5005;
int cnt[maxN][2][2];
int s[maxN];
int n, m;
vector < int > allLeft[maxN], allRight[maxN];
int hisL[maxN], hisR[maxN], hisF[maxN];
const int maxK = maxN * maxN + 10;
int inv[maxK];
int curL = 0;
int curR = n + 1;
int prod = 1;
short cur = 0;
pair < int, int > ans = make_pair(0, 1);
void upd(pair < int, int >& cur) {
    if (ans.first > cur.first) return;
    if (ans.first < cur.first) {
        ans = cur;
        return;
    }
    ans.second = sum(ans.second, cur.second);
}
void init() {
    curL = 0;
    curR = n + 1;
    prod = 1;
    cur = 0;
}
//pair < short, int > anses[maxN][maxN];
pair < int, int > ways(int v) {
    int ways2 = (cnt[v][1][0] + cnt[v][1][1]) * (cnt[v][0][1] + cnt[v][1][1]) - cnt[v][1][1];
    if (ways2) return {2, ways2};
    int ways1 = cnt[v][0][1] + 2 * cnt[v][1][1] + cnt[v][1][0];
    if (ways1) return {1, ways1};
    return {0, 1};
}
void shiftLeft() {
    curL++;
    for (int v : allLeft[curL]) {
        if (hisR[v] != -1 && hisR[v] >= curR) {
            cnt[hisF[v]][0][1]--;
            cnt[hisF[v]][1][1]++;
        }
        else {
            cnt[hisF[v]][0][0]--;
            cnt[hisF[v]][1][0]++;
        }
    }
}

void shiftRight() {
    curR--;
    for (int v : allRight[curR]) {
        if (hisL[v] != -1 && hisL[v] <= curL) {
            cnt[hisF[v]][1][0]--;
            cnt[hisF[v]][1][1]++;
        }
        else {
            cnt[hisF[v]][0][0]--;
            cnt[hisF[v]][0][1]++;
        }
    }
}
pair < int, int > anses[2][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    /*for (int i = 2; i < maxK; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
    }*/
    cin >> n >> m;
    //n = 5000;
    //m = 5000;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        //s[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int f, h;
        cin >> f >> h;
        //f = 1;
        //h = i;
        int coph = h;
        int indL = -1;
        for (int j = 1; j <= n; j++) {
            if (coph && f == s[j]) coph--;
            if (coph == 0) {
                indL = j;
                break;
            }
        }
        coph = h;
        int indR = -1;
        for (int j = n; j >= 1; j--) {
            if (coph && f == s[j]) coph--;
            if (coph == 0) {
                indR = j;
                break;
            }
        }
        hisF[i] = f;
        hisL[i] = indL;
        hisR[i] = indR;
        if (indL != -1) allLeft[indL].emplace_back(i);
        if (indR != -1) allRight[indR].emplace_back(i);
    }
    allLeft[0].emplace_back(0);
    for (int l = 0; l <= n; l++) {
        for (int ind : allLeft[l]) {
            init();
            memset(cnt, 0, sizeof cnt);
            for (int i = 0; i < l; i++) shiftLeft();
            for (int r = n + 1; r > l + 1; r--) shiftRight();
            pair < int, int > cur = {0, 0};
            cur.second = 1;
            for (int p = 1; p <= n; p++) {
                if (ind != 0 && p == hisF[ind]) {
                    if (hisR[ind] != -1 && hisR[ind] >= l + 1) {
                        cnt[hisF[ind]][1][1]--;
                    }
                    else {
                        cnt[hisF[ind]][1][0]--;
                    }
                    if (cnt[hisF[ind]][1][1] + cnt[hisF[ind]][0][1]) {
                        cur.first += 2;
                        cur.second = mult(cur.second, cnt[hisF[ind]][1][1] + cnt[hisF[ind]][0][1]);
                    }
                    else {
                        cur.first++;
                    }
                }
                else {
                    auto it = ways(p);
                    cur.first += it.first;
                    cur.second = mult(cur.second, it.second);
                }
            }
            upd(cur);
        }
    }
    if (ans.first == 0) ans.second = 1;
    cout << ans.first << " " << ans.second;
    return 0;
}