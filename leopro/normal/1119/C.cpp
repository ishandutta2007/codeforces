#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > A(n, vector<int>(m)), B(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> B[i][j];
        }
    }
    vector<int> A_rows(n, 0), A_cols(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] != B[i][j]){
                A_rows[i]++;
                A_cols[j]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (A_rows[i] % 2 == 1){
            cout << "No\n";
            return 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (A_cols[i] % 2 == 1){
            cout << "No\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}