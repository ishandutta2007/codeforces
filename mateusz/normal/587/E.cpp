#include <bits/stdc++.h>

using namespace std;

const int LOG = 31, BASE = 262144, N = 200005;

int tab[BASE];

class Node {

public:
    vector<int> numbers;
};

Node merge(const Node &a, const Node &b) {
    Node ret;
    vector<pair<int, int> > tmp;
    for (int i = 0; i < a.numbers.size(); i++) {
        tmp.push_back(make_pair(a.numbers[i], a.numbers[i]));
    }
    for (int i = 0; i < b.numbers.size(); i++) {
        tmp.push_back(make_pair(b.numbers[i], b.numbers[i]));
    }

    for (int i = 0; i < LOG; i++) {
        for (int j = 0; j < tmp.size(); j++) {
            if ((tmp[j].first & (1 << i))) {
                ret.numbers.push_back(tmp[j].second);
                swap(tmp[j], tmp.back());
                int x = tmp.back().first;
                tmp.pop_back();
                for (int k = 0; k < tmp.size(); k++) {
                    if ((tmp[k].first & (1 << i))) {
                        tmp[k].first ^= x;
                    }
                }
                break;
            }
        }
    }
    return ret;
}

Node tree[2 * BASE + 1];
int tree2[2 * BASE + 1];
int n, m, type, l, r, k;

void insert2(int posa, int posb, int k) {
    posa += BASE;
    posb += BASE;
    tree2[posa] ^= k;
    if (posa != posb) {
        tree2[posb] ^= k;
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            tree2[posa + 1] ^= k;
        }
        if (posb % 2 == 1) {
            tree2[posb - 1] ^= k;
        }
        posa /= 2;
        posb /= 2;
    }
}

int query2(int pos) {
    int ret = 0;
    pos += BASE;
    while (pos >= 1) {
        ret ^= tree2[pos];
        pos /= 2;
    }
    return ret;
}

void insert(int pos, int w) {
    pos += BASE;
    if (tree[pos].numbers.empty()) {
        tree[pos].numbers.push_back(w);
    } else {
        tree[pos].numbers.back() ^= w;
        if (tree[pos].numbers.back() == 0) {
            tree[pos].numbers.pop_back();
        }
    }
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
        pos /= 2;
    }
}

Node query(int posa, int posb) {
    if (posa > posb) {
        Node r;
        return r;
    }
    posa += BASE;
    posb += BASE;
    Node ret = tree[posa];
    if (posa != posb) {
        ret = merge(ret, tree[posb]);
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = merge(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = merge(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int ask(int l, int r) {
    Node p = query(l + 1, r);
    Node q;
    int w = query2(l);
    if (w > 0) {
        q.numbers.push_back(w);
    }
    return merge(p, q).numbers.size();
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    for (int i = 1; i <= n; i++) {
        tree2[i + BASE] = tab[i];
    }

    for (int i = 2; i <= n; i++) {
        Node v;
        if ((tab[i] ^ tab[i - 1]) > 0) {
            v.numbers.push_back(tab[i] ^ tab[i - 1]);
        }
        tree[i + BASE] = v;
    }

    for (int i = BASE - 1; i >= 1; i--) {
        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    while (m--) {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1) {
            scanf("%d", &k);
            insert2(l, r, k);
            insert(l, k);
            insert(r + 1, k);
        } else {
            printf("%d\n", (1 << (ask(l, r))));
        }
    }

    return 0;
}