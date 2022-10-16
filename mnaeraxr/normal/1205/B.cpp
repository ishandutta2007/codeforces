#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;
const int BIT = 60;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vi> mat(BIT, vi(BIT, oo));

    vector<int> total(BIT);

    for (int i = 0; i < BIT; ++i)
        mat[i][i] = 0;

    int answer = oo;

    for (int i = 0; i < n; ++i){
        int64 x; cin >> x;

        vector<int> b;

        for (int j = 0; j < BIT; ++j)
            if (x >> j & 1) b.push_back(j);

        for (auto j : b)
                if (++total[j] == 3){
                    cout << 3 << endl;
                    exit(0);
                }

        for (auto j : b)
            for (auto k : b)
                if (k > j){
                    if (mat[j][k] > 2)
                        answer = min(answer, mat[j][k] + 2);
                }

        for (auto j : b)
            for (auto k : b)
                if (k > j){
                    if (mat[j][k] > 2) {
                        for (int a = 0; a < BIT; ++a)
                            for (int b = 0; b < BIT; ++b){
                                mat[a][b] = min(mat[a][b], mat[a][j] + 2 + mat[k][b]);
                                mat[a][b] = min(mat[a][b], mat[a][k] + 2 + mat[j][b]);
                            }
                    }
                }
    }

    if (answer == oo) answer = -2;
    cout << answer / 2 << endl;

    return 0;
}