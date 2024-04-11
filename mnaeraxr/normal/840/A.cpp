#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

int A[maxn], B[maxn];
int X[maxn], Y[maxn];
int answer[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> A[i];

    for (int i = 0; i < n; ++i)
        cin >> B[i];

    iota(X, X + n, 0);
    iota(Y, Y + n, 0);

    sort(X, X + n, [&](int a, int b){
        return B[a] < B[b];
    });

    sort(Y, Y + n, [&](int a, int b){
        return A[a] < A[b];
    });

    for (int i = 0; i < n; ++i)
        answer[X[i]] = A[Y[n - i - 1]];

    for (int i = 0; i < n; ++i)
        cout << answer[i] << " ";
    cout << endl;

    return 0;
}