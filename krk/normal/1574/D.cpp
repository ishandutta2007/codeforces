#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10;

int n;

struct node {
    int cur[Maxn];
    node() {
        fill(cur, cur + n, 0);
    }
    bool operator<(const node &b) const {
        for (int i = 0; i < n; i++)
            if (cur[i] != b.cur[i])
                return cur[i] < b.cur[i];
        return false;
    }
    bool operator==(const node &b) const {
        for (int i = 0; i < n; i++)
            if (cur[i] != b.cur[i])
                return false;
        return true;
    }
};

typedef pair <int, node> in;

vector <int> B[Maxn];
set <node> banned;
set <in> S;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c; scanf("%d", &c);
        B[i].resize(c);
        for (int j = 0; j < c; j++)
            scanf("%d", &B[i][j]);
    }
    int m; scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        node cur;
        for (int j = 0; j < n; j++) {
            scanf("%d", &cur.cur[j]);
            cur.cur[j]--;
        }
        banned.insert(cur);
    }
    node v;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        v.cur[i] = int(B[i].size()) - 1;
        sum += B[i].back();
    }
    S.insert(in(sum, v));
    while (!S.empty()) {
        auto it = S.end(); it--;
        int sum = it->first;
        node v = it->second; S.erase(it);
        if (banned.find(v) == banned.end()) {
            for (int i = 0; i < n; i++)
                printf("%d%c", v.cur[i] + 1, i + 1 < n? ' ': '\n');
            return 0;
        }
        for (int i = 0; i < n; i++)
            if (v.cur[i] > 0) {
                sum -= B[i][v.cur[i]];
                v.cur[i]--;
                sum += B[i][v.cur[i]];
                S.insert(in(sum, v));
                sum -= B[i][v.cur[i]];
                v.cur[i]++;
                sum += B[i][v.cur[i]];
            }
    }
    return 0;
}