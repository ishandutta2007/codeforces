#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) do { cout << (ans) << '\n'; exit(0); } while(0)

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int &x: s) cin >> x;
    sort(s.begin(), s.end());
    auto go = [&](auto go, vector<int> size, vector<int> deg, int degV1, vector<int> stack, int i, int maxDepth) -> void {
        if (i == n) {
            for (int v: stack) if (deg[v] == 1) return;
            auto copy = size;
            sort(copy.begin(), copy.end());
            if (copy == s) answer("YES");
            return;
        }
        if (n - i < degV1) return;
        int newMaxDepth = stack.size();
        if (stack.size() == maxDepth) stack.pop_back();
        for (int x: stack) size[x]++;
        while (!stack.empty()) {
            if (deg[stack.back()] == 1) degV1--;
            if (++deg[stack.back()] == 1) degV1++;
            stack.push_back(i);
            go(go, size, deg, degV1, stack, i + 1, newMaxDepth == stack.size() ? newMaxDepth : maxDepth);
            stack.pop_back();
            if (deg[stack.back()] == 1) degV1--;
            if (--deg[stack.back()] == 1) degV1++;
            if (deg[stack.back()] == 1) return;
            size[stack.back()]--;
            stack.pop_back();
        }
    };
    go(go, vector(n, 1), vector(n, 0), 0, {0}, 1, n);
    cout << "NO\n";
}