#include <bits/stdc++.h>

using namespace std;

const int N = 200005, BASE = 131072 * 2;

int n, q;
int tab[N];
vector<int> positions[N], begins[N], endings[N];
bool done[N];
int ans[N];
int tree[2 * BASE + 5];

void insert(int pos, int w) {
    pos += BASE;
    tree[pos] = w;
    pos /= 2;
    while (pos) {
        tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
        pos /= 2;
    }
}

int query(int posa, int posb) {
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

    scanf("%d %d", &n, &q);
    
    bool isQ = false;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        if (tab[i] == q) isQ = true;
        if (tab[i] != 0) {
            insert(i, 1);
            positions[tab[i]].push_back(i);
        }
    }
    
    if (!isQ) {
        bool good = false;
        for (int i = 1; i <= n; i++) {
            if (tab[i] == 0) {
                tab[i] = q;
                good = true;
                insert(i, 1);
                positions[q].push_back(i);
                break;
            }
        }
        if (!good) {
            printf("NO\n");
            return 0;
        }
    }
    
    int unused = -1;
    for (int i = q; i >= 1; i--) {
        if (positions[i].empty()) {
            unused = max(unused, i);
            continue;
        }
        for (int pos : positions[i]) {
            insert(pos, 0);
        }
        int first = positions[i][0];
        int last = positions[i].back();
        if (query(first, last) != 0) {
            printf("NO\n");
            return 0;
        }
        begins[first].push_back(i);
        endings[last].push_back(i);
    }
    
    priority_queue<int> Q;
    for (int i = 1; i <= n; i++) {
        for (int col : begins[i]) {
            Q.push(col);
        }
        while (!Q.empty() && done[Q.top()]) {
            Q.pop();
        }
        if (Q.empty()) {
        } else {
            ans[i] = Q.top();
        }
        for (int col : endings[i]) {
            done[col] = true;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0) ans[i] = ans[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        if (ans[i] == 0) ans[i] = ans[i + 1];
    }
    
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}