#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5, BASE = 262144, N = 200005;

int tree[2 * BASE + 5];
int n;
pair<pair<int, int>, pair<int, int> > coord[N];
pair<pair<int, int>, pair<int, int> > realCoords[N];
vector<pair<int, pair<int, int> > > iksy, igreki;
vector<pair<pair<int, int>, int> > os[N];
vector<int> poczatki[N], konce[N];
int diff[N];
int cnt[2 * BASE];

void insert(int pos, int w) {
    pos += BASE;
    cnt[pos] += w;
    if (cnt[pos] == 0)
        w = -1;
    else if (cnt[pos] == 1 && w == 1) {
        w = 1;
    } else {
        w = 0;
    }
    while (pos >= 1) {
        tree[pos] += w;
        pos /= 2;
    }
}

int query(int posa, int posb) {
    if (posa > posb) {
        return 0;
    }

    posa += BASE;
    posb += BASE;

    int ret = tree[posa];
    if (posa != posb) {
        ret += tree[posb];
    }

    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret += tree[posa + 1];
        }
        if (posb % 2 == 1) {
            ret += tree[posb - 1];
        }
        posa /= 2;
        posb /= 2;
    }

    return ret;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &coord[i].first.first, &coord[i].first.second, &coord[i].second.first, &coord[i].second.second);
        if (coord[i].first.first > coord[i].second.first) {
            swap(coord[i].first.first, coord[i].second.first);
        }
        if (coord[i].first.second > coord[i].second.second) {
            swap(coord[i].first.second, coord[i].second.second);
        }
        realCoords[i] = coord[i];
        iksy.push_back({coord[i].first.first, {i, 0}});
        iksy.push_back({coord[i].second.first, {i, 1}});
        igreki.push_back({coord[i].first.second, {i, 0}});
        igreki.push_back({coord[i].second.second, {i, 1}});
    }

    sort(iksy.begin(), iksy.end());
    sort(igreki.begin(), igreki.end());
    int in = 0;
    for (int i = 0; i < iksy.size(); i++) {
        if (i == 0 || iksy[i].first != iksy[i - 1].first) {
            in++;
        }
        if (iksy[i].second.second == 0) {
            coord[iksy[i].second.first].first.first = in;
        } else {
            coord[iksy[i].second.first].second.first = in;
        }
    }

    in = 0;
    for (int i = 0; i < igreki.size(); i++) {
        if (i == 0 || igreki[i].first != igreki[i - 1].first) {
            in++;
            if (i > 0)
                diff[in - 1] = igreki[i].first - igreki[i - 1].first;
        }
        if (igreki[i].second.second == 0) {
            coord[igreki[i].second.first].first.second = in;
        } else {
            coord[igreki[i].second.first].second.second = in;
        }
    }
    diff[in] = 1;

    for (int i = 1; i <= n; i++) {
        if (coord[i].first.second == coord[i].second.second) {
            os[coord[i].first.second].push_back({{coord[i].first.first, coord[i].second.first}, i});
        } else {
            poczatki[coord[i].first.second].push_back(coord[i].first.first);
            konce[coord[i].second.second].push_back(coord[i].second.first);
        }
    }

    long long ans = 0;
    for (int i = 1; i <= in; i++) {
        sort(os[i].begin(), os[i].end());

        for (int j = 0; j < poczatki[i].size(); j++) {
            insert(poczatki[i][j], 1);
        }

        ans += (long long)query(1, 2 * n);
        int maxEnd = 0;
        int maxRealEnd = -INF;
        for (int j = 0; j < os[i].size(); j++) {
            int beg = os[i][j].first.first;
            int nd = os[i][j].first.second;
            int in = os[i][j].second;
            beg = max(beg, maxEnd + 1);
            int realBeg = max(maxRealEnd + 1, realCoords[in].first.first);
            int realEnd = realCoords[in].second.first;
            if (beg > nd) {
                continue;
            }
            ans += realEnd - realBeg + 1 - query(beg, nd);
            maxEnd = max(maxEnd, nd);
            maxRealEnd = max(maxRealEnd, realEnd);
        }

        for (int j = 0; j < konce[i].size(); j++) {
            insert(konce[i][j], -1);
        }
        ans += (long long)query(1, 2 * n) * (diff[i] - 1);
    }
    printf("%I64d\n", ans);
}