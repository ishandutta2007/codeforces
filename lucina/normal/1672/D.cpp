#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];
bool used[nax];
vector <int> where_a[nax];
vector <int> where_b[nax];

bool solve() {
    cin >> n;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
    }
    multiset <int> keep;

    int pos = n;
    b[n + 1] = a[n + 1] = 0;
    for (int i = n ; i >= 1 ; -- i) {
        if (a[i] == b[pos]) {
            pos -= 1;
            continue;
        }
        if (b[pos] == b[pos + 1]) {
            keep.insert(b[pos]);
            pos --;
            i ++;
            continue;
        }
        if (keep.find(a[i]) == keep.end()) return false;
        keep.erase(keep.find(a[i]));
    }
    return keep.empty();
}

int main() {
    int T;
    //cin.tie(0)->sync_with_stdio(false);
    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
/**
    long time no rated round
*/