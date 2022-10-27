#include<bits/stdc++.h>
using namespace std;


/**
    a[i] ^ j != a[j] ^ i
    a[i] ^ i != a[j] ^ i
    what is important when you can to compare value it

    MSB(a[i] ^ i ^ a[j] ^ j)

    So, why don't try keeping this in trie?

    Let's say  MSB(a[i] ^ i ^ a[j] ^ j) = k
    then for bit (k + 1, ..., 30), the values will be exactly the same
    for both (a[i] ^ i) and (a[j] ^ j)

    So, when you are trying to descent trie,
    We descend until (k + 1) and look at (other subtrees)
    How can we know that this subtree is valid?

    It means that a[i] ^ j == 1 and a[j] ^ i == 0

    Look at k-th bit
    a[i] ^ i = 0 and a[j] ^ j = 1
    or
    a[i] ^ i = 1 and a[j] ^ j = 0

    we can deduced that
    a[i]  = ? and a[j] ^ j ^ i = ? ^ 1
    so to have a[i] ^ j, we need to have j
    equal to (? ^ 1)

    So in each trie node, we will store,
    the maximum values in subtree such that this bits of (index) is 0 or 1
*/


struct Node {
    Node * child[2];
    int dp[2];

    Node() : child() {
        memset(dp, -1, sizeof(dp));
        /**
            Lesson!

            Uninitialized pointer is not nullptr!!
        */
    }
};
Node * root;
const int L = 18;
void add_to_trie(int a, int j, int sz) {
    Node *v = root;
    int val = a ^ j;
    for (int k = L ; k >= 0 ; -- k) {
        int bit = val >> k & 1;
        if (!(v->child[bit])) {
            v->child[bit] = new Node();
        }
        int j_bit = j >> k & 1;
        v = v->child[bit];
        v->dp[j_bit] = max(v->dp[j_bit], sz);
    }
}

int query_trie(int a, int i) {
    Node *v = root;
    int val = a ^ i;
    int res = 1;
    for (int k = L ; k >= 0 ; -- k) {
        int this_bit = val >> k & 1;
        if (v->child[this_bit ^ 1]) {
            int a_bit = a >> k & 1;
            int j_bit = a_bit ^ 1;
            int r = v->child[this_bit ^ 1]->dp[j_bit];
            if (r != -1) {
                res = max(res, r + 1);
            }
        }
        if (!(v->child[this_bit])) v->child[this_bit] = new Node();
        v = v->child[this_bit];
    }
    return res;
}

const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    root = new Node();
    int ans = 0;

    for (int i = 0 ; i < n ; ++ i) {
        int res = query_trie(a[i], i);
        ans = max(ans, res);
        add_to_trie(a[i], i, res);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}