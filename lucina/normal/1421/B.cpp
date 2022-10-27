#include<bits/stdc++.h>
using namespace std;
int const nax = 210;
char a[nax][nax];
int n;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;


    for (cin >> T ; T -- ;) {
        cin >> n;

        for (int i = 1 ; i <= n ; ++ i)
            cin >> a[i] + 1;
        int x = a[1][2] - '0';
        int y = a[2][1] - '0';
        int z = a[n - 1][n] - '0';
        int w = a[n][n - 1] - '0';

        vector < pair <int, int>> foo;
        vector < pair <int, int>> real_ans;

        for (int c = 0 ;c < 2 ; ++ c) {
            foo.clear();
            if (x != c) foo.emplace_back(1, 2);
            if (y != c) foo.emplace_back(2, 1);
            if (z != (c ^ 1)) foo.emplace_back(n - 1, n);
            if (w != (c ^ 1)) foo.emplace_back(n, n - 1);
            if (foo.size() <= 2) real_ans.swap(foo);
        }
        cout << real_ans.size() << '\n';

        for (auto [x, y] : real_ans)
            cout << x << ' ' << y << '\n';
    }
}