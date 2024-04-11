
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// if one switches vertically, the next one down must also switch vertically
// 1234
// 3412
// 1234
// 3412
// the 4 letters are partitioned in groups of 2, assigned to alternating rows (cols)
// for each row (col) and each pair of letters, find number of mismatches

const int N = 3e5 + 5;
int n, m;
string s[N];
int row[N][4][4], col[N][4][4];
char cc[4] = {'A', 'C', 'G', 'T'};
map<char, int> ma = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> s[i];
    }
    rep(i, 0, n) rep(a, 0, 4) rep(b, 0, 4) rep(j, 0, m) {
        row[i][a][b] += (s[i][j] != cc[j % 2 == 0 ? a : b]);
        col[j][a][b] += (s[i][j] != cc[i % 2 == 0 ? a : b]);
    }
    int cost = INT_MAX;
    int A = 0, B = 0;
    bool R = true;
    rep(a, 0, 4) rep(b, a + 1, 4) {
        int c = 0;
        while(c == a || c == b) c++;
        int d = c + 1;
        while(d == a || d == b) d++;
        int costrow = 0, costcol = 0;
        rep(i, 0, n) {
            if(i % 2 == 0) {
                costrow += min(row[i][a][b], row[i][b][a]);
            }else {
                costrow += min(row[i][c][d], row[i][d][c]);
            }
        }
        rep(j, 0, m) {
            if(j % 2 == 0) {
                costcol += min(col[j][a][b], col[j][b][a]);
            }else {
                costcol += min(col[j][c][d], col[j][d][c]);
            }
        }
        if(costrow < cost) {
            A = a; B = b; R = true;
            cost = costrow;
        }
        if(costcol < cost) {
            A = a; B = b; R = false;
            cost = costcol;
        }
    }
    int C = 0;
    while(C == A || C == B) C++;
    int D = C + 1;
    while(D == A || D == B) D++;
    // cout << A << " " << B << " " << R << '\n';
    if(R) {
        rep(i, 0, n) {
            rep(j, 0, m) {
                if(i % 2 == 0) {
                    cout << cc[((j % 2) ^ (row[i][A][B] < row[i][B][A])) ? A : B];
                }else {
                    cout << cc[((j % 2) ^ (row[i][C][D] < row[i][D][C])) ? C : D];
                }
            }
            cout << '\n';
        }
    }else {
        rep(i, 0, n) {
            rep(j, 0, m) {
                if(j % 2 == 0) {
                    cout << cc[((i % 2) ^ (col[j][A][B] < col[j][B][A])) ? A : B];
                }else {
                    cout << cc[((i % 2) ^ (col[j][C][D] < col[j][D][C])) ? C : D];
                }
            }
            cout << '\n';
        }
    }
}