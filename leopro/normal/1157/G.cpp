#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct ans {
    bool good;

    ans() {
        good = false;
    }

    vector<int> hor, ver;

    ans(vector<int> h, vector<int> v) {
        hor = h;
        ver = v;
        good = true;
    }
};

ans possible(vector<vector<int>> matrix, int n, int m, int row, bool change_r) {
    vector<int> hor(n, -1);
    vector<int> ver(m, -1);
    int r = !row;

    hor[r] = change_r;
    for (int j = 0; j < m; ++j) {
        ver[j] = (r < row == matrix[r][j]) ^ change_r;
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < m; ++j) {
            if (hor[i] == !(matrix[i][j] ^ ver[j])) return ans();
            hor[i] = matrix[i][j] ^ ver[j];
        }
    }
    for (int i = row + 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (hor[i] == !(matrix[i][j] == ver[j])) return ans();
            hor[i] = matrix[i][j] == ver[j];
        }
    }
    hor[row] = matrix[row][0] ^ ver[0];
    int cur = 0;
    for (int j = 0; j < m; ++j) {
        if ((matrix[row][j] ^ hor[row] ^ ver[j]) > cur) cur++;
        if ((matrix[row][j] ^ hor[row] ^ ver[j]) < cur) return ans();
    }
    return ans(hor, ver);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    if (n == 1) {
        cout << "YES\n0" << endl;
        for (int j = 0; j < m; ++j) cout << matrix[0][j];
        cout << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        ans a = possible(matrix, n, m, i, true);
        if (a.good) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) cout << a.hor[i];
            cout << endl;
            for (int j = 0; j < m; ++j) cout << a.ver[j];
            return 0;
        }
        a = possible(matrix, n, m, i, false);
        if (a.good) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) cout << a.hor[i];
            cout << endl;
            for (int j = 0; j < m; ++j) cout << a.ver[j];
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}