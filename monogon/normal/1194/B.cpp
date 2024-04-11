
#include <iostream>
#include <climits>

#define ll long long
using namespace std;

const int MAX_N = 5e4 + 5, MAX_MN = 4e5 + 5;
int q, n, m;
string s;
bool mat[MAX_MN];
int r[MAX_N], c[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> m;
        fill(r, r + n, 0);
        fill(c, c + m, 0);
        for(int i = 0; i < n; i++) {
            cin >> s;
            for(int j = 0; j < m; j++) {
                mat[m * i + j] = (s[j] == '*');
                r[i] += mat[m * i + j];
                c[j] += mat[m * i + j];
            }
        }
        int M = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                M = min(M, m + n - r[i] - c[j] - !mat[m * i + j]);
            }
        }
        cout << M << endl;
    }
}