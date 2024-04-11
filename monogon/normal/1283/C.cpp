
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, f[N];
bool recv[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
        recv[f[i]] = true;
    }
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; i++) {
        if(recv[i]) continue;
        int tail = i;
        while(f[tail]) tail = f[tail];
        v.emplace_back(i, tail);
    }
    int m = v.size();
    for(int i = 0; i < m; i++) {
        f[v[i].second] = v[(i + 1) % m].first;
    }
    for(int i = 1; i <= n; i++) {
        cout << f[i] << " ";
    }
    cout << endl;
}