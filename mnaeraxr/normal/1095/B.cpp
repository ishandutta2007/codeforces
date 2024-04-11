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

    vector<int> v(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    cout << min(v[n - 2] - v[0], v[n - 1] - v[1]) << endl;

    return 0;
}