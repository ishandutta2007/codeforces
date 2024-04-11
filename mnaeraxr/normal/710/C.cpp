#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

bool mat[100][100];

void build(int n, int p){
    if (n == 1){
        mat[p][p] = true;
    }
    else{
        for (int i = 1; i < n - 1; ++i){
            mat[p][p + i] = 1;
            mat[p + n - 1][p + i] = 1;
        }
        mat[p + n / 2][p] = 1;
        mat[p + n / 2][p + n - 1] = 1;
        build(n - 2, p + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int n; cin >> n;

    build(n, 0);

    int odd = 1, even = 2;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (mat[i][j]){
                cout << odd << " ";
                odd += 2;
            }
            else{
                cout << even << " ";
                even += 2;
            }
        }
        cout << endl;
    }

    return 0;
}