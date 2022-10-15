#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool IsGood(const multiset<int> &ans, int h) {
    int i = ans.size();
    int H = 0;
    for (int bottle: ans) {
        --i;
        if (i % 2 == 1) {
            if (H + bottle > h) {
                return false;
            }
            continue;
        }
        H += bottle;
        if (H > h) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    multiset<int> ans;
    ans.clear();
    for (int k = 0; k < n; ++k) {
        ans.insert(a[k]);
        if (!IsGood(ans, h)){
            cout << k << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}