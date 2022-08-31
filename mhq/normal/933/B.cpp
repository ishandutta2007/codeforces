#include <bits/stdc++.h>
using namespace std;
long long p;
int k;
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> p >> k;
    vector < int > ans;
    int step = 0;
    while (p > 0) {
        if (step == 0) {
            ans.push_back(p % k);
            p = (p - (p % k)) / k;
            step ^= 1;
        }
        else {
            if (p % k == 0) {
                ans.push_back(0);
                p = p / k;
                step ^= 1;
                continue;
            }
            ans.push_back(k - (p % k));
            p = (p + k - (p % k)) / k;
            step ^= 1;
        }
    }
    while (ans[ans.size() - 1] == 0) ans.pop_back();
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}