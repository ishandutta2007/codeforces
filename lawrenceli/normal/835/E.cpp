#include <bits/stdc++.h>

using namespace std;

int n, x, y;

int ask(const vector<int>& v) {
    if (v.empty()) return 0;
    cout << "? " << v.size() << ' ';
    for (int i : v) cout << i << ' ';
    cout << endl;

    int ret; cin >> ret;
    if (ret == -1) exit(0);
    return ret;
}

int getans(const vector<int>& v, int a = -1) {
    vector<int> cur;
    for (int i : v) cur.push_back(i);
    while (1) {
        if (cur.size() == 1) return cur[0];
        if (cur.size() == 2) {
            if (cur[0] == a) return cur[1];
            if (cur[1] == a) return cur[0];
        }

        int sze = cur.size() / 2;
        vector<int> v1, v2;
        for (int i = 0; i < sze; i++) v1.push_back(cur[i]);
        for (int i = sze; i < cur.size(); i++) v2.push_back(cur[i]);
        int exp = (v1.size() % 2 == 0 ? 0 : x);
        if (ask(v1) == exp) cur = v2;
        else cur = v1;
    }
}

int main() {
    cin >> n >> x >> y;
    vector<vector<int> > v;
    v.push_back(vector<int>(n));
    for (int i = 0; i < n; i++) v[0][i] = i + 1;
    while (1) {
        /*
        cout << "PRINT" << endl;
        for (int i = 0; i < v.size(); i++) {
            for (int j : v[i]) cout << j << ' ';
            cout << endl;
        }
        */
        vector<vector<int> > v1, v2;
        for (int i = 0; i < v.size(); i++) {
            vector<int> a, b;
            int sze = int(v[i].size()) / 2;
            for (int j = 0; j < sze; j++) a.push_back(v[i][j]);
            for (int j = sze; j < v[i].size(); j++) b.push_back(v[i][j]);
            v1.push_back(a);
            v2.push_back(b);
        }

        vector<int> vq;
        for (int i = 0; i < v1.size(); i++)
            for (int j : v1[i]) vq.push_back(j);

        int exp = (vq.size() % 2 == 0 ? 0 : x);
        if (ask(vq) == exp) { //two numbers are grouped together
            v = v1;
            for (auto& i : v2) v.push_back(i);
        } else {
            int a = getans(vq); //exactly 1 answer in vq
            for (int i = 0; i < v1.size(); i++) {
                if (find(v1[i].begin(), v1[i].end(), a) != v1[i].end()) {
                    int b = getans(v2[i], a);
                    if (a > b) swap(a, b);
                    cout << "! " << a << ' ' << b << endl;
                    return 0;
                }
            }
        }
    }
}