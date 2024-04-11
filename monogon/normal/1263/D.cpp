
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5, K = 30;
int n, dsu[N + K];
string s;

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    fill(dsu, dsu + N + K, -1);
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(char c : s) {
            join((c - 'a') + N, i);
        }
    }
    set<int> ss;
    for(int i = 0; i < n; i++) {
        ss.insert(trace(i));
    }
    cout << ss.size() << endl;
}