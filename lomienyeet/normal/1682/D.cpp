#include <iostream>
#include <vector>
void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    s = "_" + s;
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (s[i] == '1');
    if (ans & 1 || !ans) {
        std::cout <<"NO\n";
        return;
    }
    std::cout << "YES\n";
    s[0] = s[n];
    std::vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') v.push_back(i);
        else std::cout << i << " " << (i == 1 ? n : i - 1) << "\n";
    }
    for (int i = 1; i < v.size(); i++) std::cout << v[0] << " " << v[i] << "\n";
}
int32_t main() {
    int t;
    std::cin >> t;
    while (t--) solve();
}