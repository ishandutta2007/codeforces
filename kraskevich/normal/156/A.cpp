#include <iostream>
using namespace std;

int main() {
    string s, u;
    cin >> s >> u;
    int res = u.length(), n = s.length(), m = u.length();
    for(int i = -max(m, n); i < max(n, m); ++i) {
            int miss = 0;
            for(int j = 0; j < m; ++j)
                    if(i + j < 0 || i + j >= n || s[i + j] != u[j])
                         ++miss;
            res = min(res, miss);
    }
    cout << res;
    cin >> n;
    return 0;
}