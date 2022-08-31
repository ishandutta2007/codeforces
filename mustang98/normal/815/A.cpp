#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100, inf = 1000111222;

int m[max_n][max_n];
vector<int> ansrow;
vector<int> anscol;
    int N, M;

void calcR() {
    for (int i = 0; i < N; ++i) {
        int minn = 10000;
        for (int j = 0; j < M; ++j) {
            minn = min(minn, m[i][j]);
        }
        for (int j = 0; j < minn; ++j) {
            ansrow.push_back(i);
        }
        for (int j = 0; j < M; ++j) {
            m[i][j] -= minn;
        }
    }
}

void calcC() {
    for (int i = 0; i < M; ++i) {
        int minn = 10000;
        for (int j = 0; j < N; ++j) {
            minn = min(minn, m[j][i]);
        }
        for (int j = 0; j < minn; ++j) {
            anscol.push_back(i);
        }
        for (int j = 0; j < N; ++j) {
            m[j][i] -= minn;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int sum = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> m[i][j];
            sum += m[i][j];
        }
    }
    if (N > M) {
        calcC();
        calcR();
    } else {
        calcR();
        calcC();
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (m[i][j] != 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ansrow.size() + anscol.size() << "\n";
    for (int ind : ansrow) {
        cout << "row " << ind + 1 << "\n";
    }
    for (int ind : anscol) {
        cout << "col " << ind + 1 << "\n";
    }
    return 0;
}