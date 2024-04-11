
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int q, n, a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            cin >> a;
            v.push_back(a);
        }
        int i = 0;
        while(i < n) {
            auto it = min_element(v.begin() + i, v.end());
            int j = it - v.begin();
            int val = v[j];
            v.erase(it);
            v.insert(v.begin() + i, val);
            i = max(i + 1, j);
        }
        for(int val : v) {
            cout << val << " ";
        }
        cout << endl;
    }
}