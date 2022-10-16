#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> board(n - 1, vector<pii>(m));

    for (int i = 0; i < m; ++i){
        vector<int> a(n);

        for (int j = 0; j < n; ++j){
            cin >> a[j];
        }

        for (int j = 0; j + 1 < n; ++j){
            board[j][i] = {a[j] - a[n - 1], i};
        }
    }

    for (int i = 0; i + 1 < n; ++i){
        sort(board[i].begin(), board[i].end());
        reverse(board[i].begin(), board[i].end());
    }

    int answer = -1;
    int cur_best = -1;

    for (int i = 0; i + 1 < n; ++i){
        if (board[i][0].first < 0) {
            continue;
        }

        int prefix = 0;
        int best = 0;

        for (int j = 0; j < m; ++j) {
            if (board[i][j].first + prefix >= 0) {
                prefix += board[i][j].first;
                best = j + 1;
            } else {
                break;
            }
        }

        if (best > cur_best) {
            cur_best = best;
            answer = i;
        }
    }

    if (answer == -1) {
        cout << m << endl;
        for (int i = 1; i <= m; ++i){
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << m - cur_best << endl;

        for (int i = 0; i < m - cur_best; ++i) {
            cout << board[answer][m - 1 - i].second + 1 << " ";
        }

        cout << endl;
    }


    return 0;
}