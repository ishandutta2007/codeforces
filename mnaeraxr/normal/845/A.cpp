#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> value(2 * n);

    for (int i = 0; i < 2 * n; ++i)
        cin >> value[i];

    sort(value.begin(), value.end());

    cout << (value[n] > value[n - 1] ? "YES" : "NO") << endl;

    return 0;
}