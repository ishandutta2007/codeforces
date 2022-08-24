#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int resp;
    cin >> resp;
    return resp;
}
void solve() {
    int n;
    cin >> n;
    vector<int> nums(1 << n);
    iota(nums.begin(), nums.end(), 1);
    while ((int)nums.size() >= 4) {
        vector<int> new_nums;
        for (int i = 0; i < nums.size(); i += 4) {
            int x0 = nums[i];
            int x1 = nums[i + 1];
            int x2 = nums[i + 2];
            int x3 = nums[i + 3];
            int p0 = ask(x0, x2);
            if (p0 == 0) {
                int p1 = ask(x1, x3);
                assert(p1 == 1 || p1 == 2);
                if (p1 == 1) new_nums.emplace_back(x1);
                else new_nums.emplace_back(x3);
            }
            else if (p0 == 1) {
                int p1 = ask(x0, x3);
                if (p1 == 1) {
                    new_nums.emplace_back(x0);
                }
                else {
                    new_nums.emplace_back(x3);
                }
            }
            else {
                int p1 = ask(x2, x1);
                if (p1 == 1) {
                    new_nums.emplace_back(x2);
                }
                else {
                    new_nums.emplace_back(x1);
                }
            }
        }
        nums = new_nums;
    }
    if (nums.size() == 2) {
        int p0 = ask(nums[0], nums[1]);
        if (p0 == 2) swap(nums[0], nums[1]);
    }
    cout << "! " << nums[0] << endl;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}