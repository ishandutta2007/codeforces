#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];

vector <tuple <int, int, int>> ans;

int main() {

    cin.tie(0)->sync_with_stdio(false);

    cin >> n;

    int sum = 0;

    for (int i = 1 ; i <= n; ++ i) {
        cin >> a[i];
        sum ^= a[i];
    }
    // cout << sum << '\n';

    if (n % 2) {
        cout << "YES\n";

        ans.emplace_back(1, 2, 3);

        for (int i = 4 ; i <= n ; i += 2)
            ans.emplace_back(i - 1, i, i + 1);

        for (int i = n - 2 ; i - 2 >= 1 ; i -= 2)
            ans.emplace_back(i - 2, i - 1, i);

        cout << ans.size() << '\n';
        for (auto [x, y, z] : ans) {
            cout << x << ' ' << y << ' ' << z << '\n';
        }
        return 0;
    }

    if (sum != 0) {
        return cout << "NO\n", 0;
    }
    cout << "YES\n";

    int where = -1;

    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] == sum) {
            where = i;
            break;
        }
    }

    where = n;

    auto get_ind = [&](int i)->int {
        if (i >= where) return i + 1;
        else return i;
    };

    ans.emplace_back(get_ind(1), get_ind(2), get_ind(3));

    for (int i = 4 ; i < n ; i += 2)
        ans.emplace_back(get_ind(i - 1), get_ind(i), get_ind(i + 1));

    for (int i = n - 3 ; i - 2 >= 1 ; i -= 2)
        ans.emplace_back(get_ind(i - 2), get_ind(i - 1), get_ind(i));

    cout << ans.size() << '\n';

    for (auto [x, y, z] : ans)
        cout << x << ' ' << y << ' ' << z << '\n';
}