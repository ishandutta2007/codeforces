#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 524288, len = 20, inf = 1000111222;

vector<int> v;
bool has[max_n];

struct node{
    node* c0 = nullptr;
    node* c1 = nullptr;
};

node* root = new node();

void add(string s) {
    node* cur = root;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (cur->c0 == nullptr) {
                cur->c0 = new node();
            }
            cur = cur->c0;
        } else {
            if (cur->c1 == nullptr) {
                cur->c1 = new node();
            }
            cur = cur->c1;
        }
    }
}

string get_bin(int n) {
    string ans(len, '0');
    for (int i = 0; i < len; ++i) {
        if (n & (1 << i)) {
            ans[i] = '1';
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int get_int(string s) {
    int ans = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            ans |= (1 << i);
        }
    }
    return ans;
}

string get(string best) {
    string ans = "";
    node* cur = root;
    for (int i = 0; i < best.size(); ++i) {
        if (best[i] == '0') {
            if (cur->c0 != nullptr) {
                ans += '0';
                cur = cur->c0;
            } else {
                ans += '1';
                cur = cur->c1;
            }
        } else {
            if (cur->c1 != nullptr) {
                ans += '1';
                cur = cur->c1;
            } else {
                ans += '0';
                cur = cur->c0;
            }
        }
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, x = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        has[a] = 1;
    }
    for (int i = 0; i < max_n; ++i) {
        if (!has[i]) {
            add(get_bin(i));
        }
    }
    for (int i = 0; i < m; ++i) {
        int curx;
        cin >> curx;
        x ^= curx;
        cout << (x ^ get_int(get(get_bin(x)))) << endl;
    }
    return 0;
}