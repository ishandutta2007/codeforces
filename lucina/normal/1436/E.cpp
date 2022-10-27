#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;
int n;
int a[nax];
int sg[nax << 2];
int lst_occ[nax];
/**
    we have O(n) subarray MEX queries.

    Let's process from left to right.
    And let's answer query when right border equal to "R"
    offline.

    Let's understand the segment tree
    that each left represent number from 1...n

    each node will represent last node that contains this number

    To get the answer for L.

    we want to know the first number in this tree that

    last_occ < L

    Now this is "descending" value in segment tree

    Thanks to writer for defined MEX in positive field.
*/

void pull(int v) {
    sg[v] = min(sg[v << 1], sg[v << 1 | 1]);
}

void update(int v, int x, int y, int pos, int val) {
    if (x == y) {
        sg[v] = val;
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) update(v << 1, x, mid, pos, val);
        else update(v << 1 | 1, mid + 1, y, pos, val);
        pull(v);
    }
}

int find(int v, int l, int r, int val) {
    /**
        find first number that < val
    */
    if (l == r) {
        return l;
    } else {
        int mid = l + r >> 1;
        if (sg[v << 1] < val) return find(v << 1, l, mid, val);
        else return find(v << 1 | 1, mid + 1, r, val);
    }
}


vector <int> where[nax];
vector <int> queries[nax];
bool bar[nax];


int main() {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        where[a[i]].push_back(i);
    }


    for (int i = 1 ; i <= n ; ++ i) {
        int lst = 1;
        for (int j : where[i]) {
            if (j - 1 >= lst) queries[j - 1].push_back(lst);
            lst = j + 1;
        }
        if (n >= lst) queries[n].push_back(lst);
    }

    memset(lst_occ, -1, sizeof(lst_occ));

    for (int i = 1 ; i <= n ; ++ i) {
        update(1, 1, n, a[i], i);

        for (int l : queries[i]) {
            int ans = sg[1] >= l ? n + 1 : find(1, 1, n, l);
            bar[ans] = true;
         //   printf("%d\n", ans);
        }
    }

    static bool foo[nax];

    for (int i = 1 ; i <= n ; ++ i) {
        foo[a[i]] = true;
    }

    for (int i = 1 ; i <= n + 1 ; ++ i) {
        if (!foo[i]) {
            bar[i] = true;
            break;
        }
    }

    for (int i = 1 ; i <= n + 2 ; ++ i)
        if (!bar[i]) return !printf("%d\n", i);

    ///throw;
}