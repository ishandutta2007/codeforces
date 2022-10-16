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

    string s; cin >> s;

    int ones = 0;

    for (auto x : s){
        if (x == 'n')
            ones++;
    }

    int zeros = (n - 3 * ones) / 4;

    for (int i = 0; i < ones; ++i)
        cout << 1 << " ";
    for (int i = 0; i < zeros; ++i)
        cout << 0 << " ";
    cout << endl;

    return 0;
}