#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005, MX = 2E6 + 5;
 
int n, a[N];
vector<int> pr[MX];
set<int> ava;
 
void init() {
    for (int i = 2; i < MX; i++) {
        if (pr[i].empty()) {
            for (int j = i; j < MX; j += i) {
                pr[j].push_back(i);
            }
        }
        ava.insert(i);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    bool chk = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int cur = *ava.lower_bound(chk ? a[i] : 0);
        chk &= (cur == a[i]);
        for (int &p : pr[cur]) {
            for (int j = p; j < MX; j += p) {
                ava.erase(j);
            }
        }
        cout << cur << " ";
    }
}