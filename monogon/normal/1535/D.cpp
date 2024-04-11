
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = (1 << 18);
int tree[8 * N];
string s;

void hmm(int i) {
    tree[i] = 0;
    if(s[i] != '1') tree[i] += tree[2 * i + 2];
    if(s[i] != '0') tree[i] += tree[2 * i + 1];
}

void build(int i, int l, int r) {
    if(l == r) {
        if(s[i] == '?') tree[i] = 2;
        else tree[i] = 1;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    hmm(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, q;
    cin >> k >> s >> q;
    fill(tree, tree + 8 * N, 1);
    reverse(all(s));
    build(0, 1, (1 << (k - 1)));
    while(q--) {
        int p; char c;
        cin >> p >> c;
        int i = (1 << k) - 1 - p;
        s[i] = c;
        while(true) {
            hmm(i);
            if(i == 0) break;
            i = (i - 1) / 2;
        }
        cout << tree[0] << '\n';
    }
}