#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

struct Node {
    bool w = false, b = false;
    bool hw = false, hb = false;

    Node* go[2];

    Node() {
        go[0] = go[1] = nullptr;
    }
};

void add(Node* v, const string& s, bool bl) {
    for (char c : s) {
        int x = c - '0';
        if (v->go[x] == nullptr) {
            v->go[x] = new Node();
        }
        v = v->go[x];
    }
    if (bl) {
        v->b = true;
        v->hb = true;
    } else {
        v->w = true;
        v->hw = true;
    }
}

void dfs(Node* v) {
    for (int i = 0; i < 2; i++) {
        if (v->go[i]) {
            dfs(v->go[i]);
            v->hb |= v->go[i]->hb;
            v->hw |= v->go[i]->hw;
        }
    }
}

string conv(int x) {
    string res;
    for (int i = 0; i < 8; i++) {
        res += '0' + (x % 2);
        x /= 2;
    }
    return string(res.rbegin(), res.rend());
}

string parse(string s) {
    int pos = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') {
            pos = i;
        }
    }

    int len = 32;
    if (pos != -1) {
        len = stoi(s.substr(pos + 1));
    }
    if (pos == -1) {
        pos = s.size();
    }
    string res;
    string cur;
    for (int i = 0; i < pos; i++) {
        if (s[i] == '.') {
            res += conv(stoi(cur));
            cur = "";
        } else {
            cur += s[i];
        }
    }
	res += conv(stoi(cur));

    return res.substr(0, len);
}

vector<string> ans;

void nein() {
    cout << -1 << "\n";
    exit(0);
}

string tob(string s) {
    int x = 0;
    for (char c : s) {
        x = 2 * x;
        if (c == '1') {
            x++;
        }
    }
    return to_string(x);
}

string make(string s) {
    int smask = s.size();
    while (s.size() < 32) {
        s += '0';
    }
    string res;
    string cur;
    for (int i = 0; i < 32; i++) {
        cur += s[i];
        if (i % 8 == 7) {
            if (!res.empty()) {
                res += '.';
            }
            res += tob(cur);
			cur = "";
        }
    }
    res += "/";
    res += to_string(smask);
    return res;
}

void solve(Node* v, string cur) {
    if (v->b && v->hw) {
        nein();
    }
	if (v->w && v->hb) {
		nein();
	}
    if (v->hb && !v->hw) {
        ans.push_back(make(cur));
        return;
    }
    for (int i = 0; i < 2; i++) {
        if (v->go[i]) {
            solve(v->go[i], cur + char('0' + i));
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    int n;
    cin >> n;

    Node* root = new Node();
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string mask = parse(s.substr(1));
        bool bl = false;
        if (s[0] == '-') {
            bl = true;
        }
        add(root, mask, bl);
    }

	dfs(root);
    solve(root, "");
    cout << ans.size() << "\n";
    for (const auto& s : ans) {
        cout << s << "\n";
    }
	return 0;
}