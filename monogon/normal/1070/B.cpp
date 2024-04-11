
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int n;
string s;

struct node {
    bool white = false, black = false;
    node *left = NULL, *right = NULL;
};

void impos() {
    cout << "-1\n";
    exit(0);
}

void ins(node *x, unsigned int l, unsigned int r, unsigned int L, unsigned int R, bool white) {
    if(white) x->white = true;
    else x->black = true;
    if(x->white && x->black && x->left == NULL && x->right == NULL) impos();
    if(L == l && R == r) {
        if(x->white && x->black) impos();
        return;
    }
    assert(l < r);
    unsigned int m = l + (r - l) / 2 + 1;
    if(R < m) {
        if(x->left == NULL) x->left = new node;
        ins(x->left, l, m - 1, L, R, white);
    }else {
        if(x->right == NULL) x->right = new node;
        ins(x->right, m, r, L, R, white);
    }
}

node *root = NULL;
vector<pair<unsigned int, unsigned int>> masks;

void solve(node *x, unsigned int l, unsigned int r) {
    if(x == NULL) return;
    int m = l + (r - l) / 2 + 1;
    if(x->white) {
        if(x->black) {
            solve(x->left, l, m - 1);
            solve(x->right, m, r);
        }
    }else if(x->black) {
        masks.emplace_back(l, r - l);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    root = new node;
    rep(i, 0, n) {
        cin >> s;
        bool white = (s[0] == '+');
        bool dig = false;
        for(char &c : s) {
            if(c == '.') c = ' ';
            else if(c == '/') {
                dig = true;
                c = ' ';
            }
        }
        stringstream ss;
        ss << s.substr(1, s.length() - 1);
        unsigned int mask = 0;
        rep(j, 0, 4) {
            int x;
            ss >> x;
            mask = (mask << 8) | x;
        }
        int num = 32;
        if(dig) {
            ss >> num;
        }
        ins(root, 0, UINT_MAX, mask, mask + ((1u << (32 - num)) - 1), white);
    }
    solve(root, 0, UINT_MAX);
    cout << sz(masks) << '\n';
    for(auto &p : masks) {
        unsigned int x, y;
        tie(x, y) = p;
        cout << ((x >> 24) & 255) << '.' << ((x >> 16) & 255) << '.' << ((x >> 8) & 255) << '.' << (x & 255) << '/';
        int i = 0;
        while((1LL << i) - 1 < y) i++;
        cout << 32-i << '\n';
    }
}