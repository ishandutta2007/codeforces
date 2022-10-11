#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;
    int n = len(s);
    for (int lines = 1;; lines++) {
        int base = n / lines;
        int extra = n % lines;
        if (base + (extra != 0) <= 20) {
            cout << lines << ' ' << base + (extra != 0) << '\n';
            int j = 0;
            for (int i = 0; i < lines; i++) {
                int cur = base + (i < extra);
                for (int delta = 0; delta < cur; delta++, j++)
                    cout << s[j];
                if (i >= extra && extra != 0)
                    cout << "*";
                cout << '\n';
            }
            return 0;
        }
    }
}