#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;

void print(int s, int k){

    for (int i = 1; i < k; ++i){
        cout << s << " " << s + i << endl;
        if (i % 2 == 0)
            cout << s + k - 1 + i << " " << s + k - 2 + i << endl;
        for (int j = 1; j < k; ++j){
            cout << s + i << " " << s + k - 1 + j << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    if (n % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }

    int tot = 2 * (2 * n - 1);
    int edg = tot * n / 2;

    cout << "YES" << endl;
    cout << tot << " " << edg << endl;

    print(1, n);
    print(2 * n, n);
    cout << 1 << " " << 2 * n << endl;

    return 0;
}