#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bool excluded[256];
int remaining;
int n;

void exclude(char w) {
    if (!excluded[w]) {
        remaining--;
    }
    excluded[w] = true;
}

bool contains(const string &w, char c) {
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == c) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    remaining = 26;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        char op;
        string w;
//         cerr << remaining << endl;

        cin >> op >> w;
//         cerr << op << endl << w << endl;
        if (op == '.') {
            for (int i = 0; i < w.size(); i++) {
                exclude(w[i]);
            }
        } else if (op == '!') {
            if (remaining == 1) {
                ans++;
            }
            for (char c = 'a'; c <= 'z'; c++) {
                if (!contains(w, c)) {
                    exclude(c);
                }
            }
        } else {
            if (remaining == 1) {
                ans++;
            }
            exclude(w[0]);
        }
    }
    
    cout << ans << endl;
    return 0;
}