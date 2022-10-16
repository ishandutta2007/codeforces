#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int N = 701;

int a[N];
bool mat[N][N];

bool A[N][N][2];
bool B[N][N][2];

short go(int b, int e, int x){
    if (e < b)
        return true;

    if (B[b][e][x])
        return A[b][e][x];

    B[b][e][x] = true;

    int u = x ? e + 1 : b - 1;

    bool &ok = A[b][e][x];

    for (int i = b; i <= e && !ok; ++i)
        ok |= mat[u][i] && go(b, i - 1, 1) && go(i + 1, e, 0);

    return ok;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> a[i];
        for (int j = 0; j < i; ++j){
            mat[i][j] = mat[j][i] = __gcd(a[i], a[j]) > 1;
        }
    }

    bool ok = false;

    for (int i = 0; i < n && !ok; ++i)
        if (go(0, i - 1, 1) && go(i + 1, n - 1, 0))
            ok = true;

    cout << (ok ? "Yes" : "No") << endl;
}