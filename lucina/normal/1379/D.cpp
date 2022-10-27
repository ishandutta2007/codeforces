#include<bits/stdc++.h>
using namespace std;
int const nax = 8e5 + 10;
int n, h, m, k;

struct fenwick {
    int bit[nax];
    fenwick () {
        memset(bit, 0, sizeof(bit));
    }
    void update (int pos, int val) {
        for (; pos < nax ; pos += pos & -pos)
            bit[pos] += val;
    }
    int get (int pos) {
        int res = 0;
        for (; pos > 0 ; pos -= pos & -pos)
            res += bit[pos];
        return res;
    }
};

pair <int, int> interval[nax];
int com[nax];
int topCom;
int id[nax];

int main () {
    scanf("%d %d %d %d", &n, &h, &m, &k);

    for (int i = 1 ; i <= n ; ++ i) {
        id[i] = i;
        int H, M;
        scanf("%d %d", &H, &M);
        if (M >= m / 2) M -= m / 2;
        interval[i] = make_pair(M + 1, M + k - 1);
        if (interval[i].first >= m / 2) interval[i].first -= m / 2, interval[i].second -= m / 2;
    }

    int top = n;

    for (int i = 1 ; i <= n;  ++ i) {
        if (interval[i].second >= m / 2) {
            interval[++top] = make_pair(0, interval[i].second - m / 2);
            interval[i].second = m / 2 - 1;
            id[top] = i;
        }
    }

    n = top;
    for (int i = 1 ; i <= n; ++ i) {
   //     printf("%d %d\n", interval[i].first, interval[i].second);
        if (interval[i].first >= 1) com[++ topCom] = interval[i].first - 1;
        com[++ topCom] = interval[i].first;
        com[++ topCom] = interval[i].second;
        com[++ topCom] = interval[i].second + 1;
    }
  //  puts("\n\n");
    sort(com + 1, com + topCom + 1);
    topCom = unique(com + 1, com + topCom + 1) - com - 1;

    fenwick f;

  //  puts("INTERVAL");
    for (int i = 1 ; i <= n ;++ i) {

        int l = lower_bound(com + 1, com + topCom + 1, interval[i].first) - com;
        int r = lower_bound(com + 1, com + topCom + 1, interval[i].second + 1) - com;
  //      printf("%d %d\n", interval[i].first, interval[i].second);
        f.update(l, 1);
        f.update(r, -1);
    }

    int mn = INT_MAX, mn_pos = -1;
    for (int i = 1 ; i <= topCom ; ++ i) {
        if (com[i] < m / 2) {
            if (f.get(i) < mn) {
                mn = f.get(i);
                mn_pos = i;
            }
        }
    }


    vector <int> cancel;
    for (int i = 1 ; i <= n ; ++ i) {
        int l = lower_bound(com + 1, com + topCom + 1, interval[i].first) - com;
        int r = lower_bound(com + 1, com + topCom + 1, interval[i].second) - com;

        if (l <= mn_pos && r >= mn_pos) cancel.push_back(id[i]);
    }

    printf("%d %d\n", int(cancel.size()), max(0, com[mn_pos]));
    for (int i : cancel) printf("%d ", i);
}
/*
    not ryza again.
*/