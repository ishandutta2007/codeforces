#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        a.push_back(1);
        while (a.size() >= 2 && a[a.size() - 2] == a.back()) {
            a.pop_back();
            a.back()++;
        }
    }
    for (int x : a)
        cout << x << " ";
    cout << endl;
}