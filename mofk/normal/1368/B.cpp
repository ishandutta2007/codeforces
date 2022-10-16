#include <bits/stdc++.h>

using namespace std;

const long long inf = 2e16;
long long val(vector <int> v) {
    long long ans = 1;
    for (auto x: v) ans = min(inf, ans * x);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    cin >> k;
    string s = "codeforces";
    vector <int> v(10, 1);
    int ptr = 0;
    while (val(v) < k) ++v[ptr], ptr = (ptr + 1) % 10;
    for (int i = 0; i < 10; ++i) for (int j = 0; j < v[i]; ++j) cout << s[i];
    cout << endl;
    return 0;
}