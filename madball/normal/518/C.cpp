#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    int n, m, k, cur, i;
    long long res = 0;
    cin >> n >> m >> k;
    vector<int> app(n);
    vector<int> pos(n);
    for (i = 0; i < n; i++) {
        cin >> app[i];
        pos[--app[i]] = i;
    }
    for (i = 0; i < m; i++) {
        cin >> cur;
        cur--;
        res += pos[cur] / k + 1;
        if (pos[cur] > 0) {
            pos[cur]--;
            pos[app[pos[cur]]]++;
            swap(app[pos[cur]], app[pos[cur] + 1]);
        }
    }
    cout << res;
    return 0;
}