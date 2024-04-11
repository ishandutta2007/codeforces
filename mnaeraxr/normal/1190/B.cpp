#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

#define FIRST "sjfnb"
#define SECOND "cslnb"

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    if (n == 1){
        cout << (a[0] % 2 == 0 ? SECOND : FIRST) << endl;
        return 0;
    }

    sort(a.begin(), a.end());

    int eq = 0;
    int64 steps = 0;

    for (int i = 0; i + 1 < n && eq <= 1; ++i){
        steps += a[i] - i;
        if (a[i] == a[i + 1]){
            eq++;

            if (a[i] == 0)
                eq++;

            if (i && a[i - 1] + 1 == a[i]){
                eq++;
            }
        }
    }

    steps += a.back() - (n - 1);

    // cout << eq << " " << steps << endl;

    if (eq >= 2){
        cout << SECOND << endl;
        return 0;
    }

    cout << (steps % 2 == 0 ? SECOND : FIRST) << endl;


    return 0;
}