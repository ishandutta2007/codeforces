#include <bits/stdc++.h>

using namespace std;

const int N = 100005, BASE = 131072;

int n, q, a, b, type;

struct Node {
    double LR;
    double MR;
    double RR;
} tree[2 * BASE];

Node merge(Node left, Node right) {
    Node v;
    v.MR = (left.RR * right.LR) / (1 - left.RR * (1 - right.LR));
    v.LR = left.LR * (right.LR + (1 - right.LR) * v.MR);
    v.RR = right.RR + (1 - right.RR) * v.MR;
    return v;
}

void insert(int pos, double w) {
    pos += BASE;
    tree[pos].LR = tree[pos].MR = tree[pos].RR = w;
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
        pos /= 2;
    }
}

Node query(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    Node retLeft = tree[posa];
    if (posa == posb) {
        return retLeft;
    }
    Node retRight = tree[posb];
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            retLeft = merge(retLeft, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            retRight = merge(tree[posb - 1], retRight);
        }
        posa /= 2;
        posb /= 2;
    }
    return merge(retLeft, retRight);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);
        insert(i, (double)a / b);
    }
    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            int i;
            scanf("%d %d %d", &i, &a, &b);
            insert(i, (double)a / b);
        } else {
            scanf("%d %d", &a, &b);
            Node v = query(a, b);
            printf("%.10f\n", v.LR);
        }
    }
}