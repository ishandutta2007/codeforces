#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <ios>

using namespace std;

typedef long long ll;

const int maxn = 100100;
const int maxlg = 20;
const int block = 300;

int n, q;

int id[2 * maxn], sl[maxn];
char s[2 * maxn]; int len;
int sa[2 * maxn], sa2[2 * maxn], grp[2 * maxn][maxlg], gs[2 * maxn];
int lt[maxn], rt[maxn];

bool cmp(int a, int b) {
    return s[a] < s[b];
}

void init() {
    for (int i = 0; i < len; i++) sa[i] = i;
    sort(sa, sa + len, cmp);
    for (int i = 0, cnt = 0; i < len; i++) {
        if (i && s[sa[i]] != s[sa[i - 1]])
            gs[++cnt] = i;

        grp[sa[i]][0] = cnt;
    }

    for (int k = 0; k < maxlg - 1; k++) {
        for (int i = 0; i < len; i++)
            if (sa[i] >= (1<<k))
                sa2[gs[grp[sa[i] - (1<<k)][k]]++] = sa[i] - (1<<k);

        for (int i = max(len - (1<<k), 0); i < len; i++)
            sa2[gs[grp[i][k]]++] = i;

        gs[0] = 0;
        for (int i = 0, cnt = 0; i < len; i++) {
            sa[i] = sa2[i];
            if (i && (sa[i] + (1<<k) >= len || sa[i - 1] + (1<<k) >= len || grp[sa[i]][k] != grp[sa[i - 1]][k] || grp[sa[i] + (1<<k)][k] != grp[sa[i - 1] + (1<<k)][k]))
                gs[++cnt] = i;

            grp[sa[i]][k + 1] = cnt;
        }
    }
}

int lcp(int a, int b) {
    int ret = 0;
    for (int k = maxlg - 1; k >= 0; k--)
        if (a < len && b < len && grp[a][k] == grp[b][k])
            ret += (1<<k), a += (1<<k), b += (1<<k);

    return ret;
}

int ql[maxn], qr[maxn], qk[maxn];
ll ans[maxn];

int pre[2 * maxn];
ll pre2[maxn];

vector<int> vqry[2 * maxn], qs[2 * maxn], qe[2 * maxn];
int bit[2 * maxn];

void upd(int i, int v) {
    for (i++; i < 2 * maxn; i += i & -i) bit[i] += v;
}

int qry(int i) {
    int ret = 0;
    for (i++; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        sl[i] = str.length();
        for (int j = 0; j < str.length(); j++)
            id[len + j] = i, s[len + j] = str[j];
        id[len + str.length()] = i;
        len += str.length() + 1;
    }

    for (int i = 0; i < q; i++) {
        cin >> ql[i] >> qr[i] >> qk[i];
        ql[i]--, qk[i]--;
    }

    init();

    //for (int i = 0; i < len; i++) cout << sa[i] << ' ';
    //cout << endl;

    for (int i = 0; i < len; i++)
        if (!i || id[i] != id[i - 1]) {
            int k = id[i];
            int j = grp[i][maxlg - 1];
            int lo = 0, hi = j;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (lcp(i, sa[mid]) >= sl[k]) hi = mid;
                else lo = mid + 1;
            }

            lt[k] = lo;

            //for (int a = j; a < len; a++) cout << lcp(i, sa[a]) << ' ';
            //cout << endl;

            lo = j + 1, hi = len;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (lcp(i, sa[mid]) < sl[k]) hi = mid;
                else lo = mid + 1;
            }

            rt[k] = lo;
        }

    //for (int i = 0; i < n; i++) cout << lt[i] << ' ' << rt[i] << endl;

    for (int i = 0; i < n; i++)
        if (sl[i] > block) {
            for (int j = 0; j < len; j++) {
                if (id[sa[j]] == i) pre[j + 1] = pre[j] + 1;
                else pre[j + 1] = pre[j];
            }

            for (int j = 0; j < n; j++)
                pre2[j + 1] = pre2[j] + pre[rt[j]] - pre[lt[j]];

            for (int j = 0; j < q; j++)
                if (qk[j] == i)
                    ans[j] = pre2[qr[j]] - pre2[ql[j]];
        }

    for (int i = 0; i < q; i++)
        if (sl[qk[i]] <= block) {
            int x = lower_bound(id, id + len, qk[i]) - id;
            while (x < len && s[x]) {
                vqry[grp[x][maxlg - 1]].push_back(i);
                x++;
            }
        }

    for (int i = 0; i < n; i++) {
        qs[lt[i]].push_back(i);
        qe[rt[i]].push_back(i);
    }

    for (int i = 0; i <= len; i++) {
        for (int j : qs[i]) upd(j + 1, 1);
        for (int j : qe[i]) upd(j + 1, -1);
        for (int j : vqry[i])
            ans[j] += qry(qr[j]) - qry(ql[j]);
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}