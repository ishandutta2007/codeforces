#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, a;
        cin >> n >> m;

        vector<int> pos(n * m + 1, 0);

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j) {
                    cin >> a;
                    pos[a] = j;
            }
        }
        int mt[n][m];
        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i) {
                cin >> a;
                mt[i][pos[a]] = a;
            }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j){
                cout << mt[i][j] << " ";
            }
            cout << '\n';
        }

    }


    return 0;
}