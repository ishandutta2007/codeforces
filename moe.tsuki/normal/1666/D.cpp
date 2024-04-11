#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        vector<int> index[26];
        size_t cnt[26] = {};
        for (size_t i = 0; i < A.size(); i++) {
            index[A[i] - 'A'].push_back(i);
        }
        for (char c: B)
            cnt[c - 'A'] += 1;
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (index[i].size() < cnt[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        vector<int> flag(A.size());
        for (int i = 0; i < 26; i++) {
            for (int j = index[i].size() - cnt[i]; j < index[i].size(); j++) {
                flag[index[i][j]] = true;
            }
        }
        string C;
        for (size_t i = 0; i < A.size(); i++)
            if (flag[i])
                C += A[i];
        if (C == B)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}