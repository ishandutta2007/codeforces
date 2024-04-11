#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n, m;
const int maxN = (int)1e5 + 100;
vector < int > whoA[maxN], whoB[maxN];
set < int > can;
char tp[maxN];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int A = 0, B = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tp[i] >> a[i];
        if (tp[i] == '+') {
            whoA[a[i]].push_back(i);
            A++;
        }
        else {
            whoB[a[i]].push_back(i);
            B++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = B + ((int)whoA[i].size()) - (int)whoB[i].size();
        if (cnt == m) can.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        if (tp[i] == '+') {
            if (can.size() == 1 && can.count(a[i])) cout << "Truth" << '\n';
            else if (can.count(a[i])) cout << "Not defined" << '\n';
            else cout << "Lie" << '\n';
        }
        else {
            if (can.size() == 1 && can.count(a[i])) cout << "Lie" << '\n';
            else if (can.count(a[i])) cout << "Not defined" << '\n';
            else cout << "Truth" << '\n';
        }
    }
    return 0;
}