#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    map<int, int> mp;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        if (x) mp[x] ++;
    }

    int ans = 0;
    for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++)
        if (it->second > 2) {
            cout << "-1\n";
            return 0;
        } else if (it->second == 2) ans++;

    cout << ans << '\n';
    return 0;
}