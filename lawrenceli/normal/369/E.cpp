#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 300100;
const int MAXP = 1000100;

int n, m, bit[MAXP];
vector<int> seg[MAXP], p[MAXN], qadj[MAXP];
map<pii, int> mp;

int query(int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

void update(int i, int v) {
    for (i++; i<MAXP; i+=i&-i) bit[i] += v;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        seg[l].push_back(r);
    }
    for (int i=0; i<m; i++) {
        int cnt; scanf("%d", &cnt); p[i].resize(cnt);
        for (int j=0; j<cnt; j++) {
            int x; scanf("%d", &x); p[i][j] = x;
            if (j == 0) qadj[0].push_back(p[i][j]-1);
            else if (p[i][j-1] + 1 <= p[i][j] - 1) qadj[p[i][j-1] + 1].push_back(p[i][j] - 1);
        }
        qadj[p[i][cnt-1]+1].push_back(MAXP-10);
    }
    for (int i=MAXP-1; i>=0; i--) {
        for (int j=0; j<seg[i].size(); j++) update(seg[i][j], 1);
        for (int j=0; j<qadj[i].size(); j++) {
            mp[pii(i, qadj[i][j])] = query(qadj[i][j]);
        }
    }
    for (int i=0; i<m; i++) {
        int num = 0;
        for (int j=0; j<p[i].size(); j++) {
            if (j == 0) num += mp[pii(0, p[i][j] - 1)];
            else num += mp[pii(p[i][j-1] + 1, p[i][j] - 1)];
        }
        num += mp[pii(p[i].back()+1, MAXP - 10)];
        printf("%d\n", n - num);
    }
    return 0;
}