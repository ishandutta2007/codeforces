#include <bits/stdc++.h>
using namespace std;
int n, m;
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}
int a[(int)1e5 + 10];
/*
    a, b -> 1, 14
    d = 13;
    d = 1;
    a a + 13
    a + 13, a + 26
    a, a + 26
    a -> a / 2
    a -> (a + 1) / 2
    1, 2
    1, 3
    2, 4
    1, 4
    3, 5
    1, 5
*/
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    set < int > s;
    for (int i = 1; i <= 1000; i++) s.insert(i);
    vector < int > ans;
    while (1) {
        if (s.size() == 0) break;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans.size(); j++) {
                for (int k = 0; k < ans.size(); k++) {
                    if (s.find(ans[i] + ans[j] - ans[k]) != s.end()) {
                        s.erase(ans[i] + ans[j] - ans[k]);
                    }
                }
            }
        }
        ans.push_back(*s.begin());
        s.erase(s.begin());
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << 0 << " ";
            else cout << ans[i - 1] + ans[j - 1] << " ";
        }
        cout << "\n";
    }
    return 0;
}