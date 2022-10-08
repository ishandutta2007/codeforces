
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// identify first and second elements.
// then transition from one pair to the next

const int N = 1e5 + 5;
int n;
int q[N][3];
int cnt[N];
map<pair<int, int>, vector<int>> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 2; i++) {
        for(int j : {0, 1, 2}) {
            cin >> q[i][j];
            cnt[q[i][j]]++;
        }
        m[{q[i][0], q[i][1]}].push_back(q[i][2]);
        m[{q[i][1], q[i][0]}].push_back(q[i][2]);
        m[{q[i][0], q[i][2]}].push_back(q[i][1]);
        m[{q[i][2], q[i][0]}].push_back(q[i][1]);
        m[{q[i][1], q[i][2]}].push_back(q[i][0]);
        m[{q[i][2], q[i][1]}].push_back(q[i][0]);
    }
    int p1 = 0, p2 = 0;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 1) {
            p1 = i;
            break;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 2 && !m[{p1, i}].empty()) {
            p2 = i;
            break;
        }
    }
    vector<int> v = {p1, p2};
    while((int) v.size() < n) {
        int i = (int) v.size() - 1;
        for(int j : m[{v[i], v[i - 1]}]) {
            if(v.size() == 2 || v[i - 2] != j) {
                v.push_back(j);
                break;
            }
        }
    }
    for(int x : v) {
        cout << x << " ";
    }
    cout << endl;
}