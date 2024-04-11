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

    int n; cin >> n;

    vector<vi> mat(n, vi(n));

    int g = 0;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> mat[i][j];
        }
    }

    int64 aa1 = 1LL * mat[0][1] * mat[0][2] / mat[1][2];

    int64 a1 = 1;

    while (a1 * a1 < aa1)
        a1++;

    assert(a1 * a1 == aa1);

    for (int i = 0; i < n; ++i){
        if (i == 0) cout << a1 << " ";
        else cout << mat[0][i] / a1 << " ";
    }

    cout << endl;


    return 0;
}