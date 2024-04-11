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

    vector<int> value(n);

    int one = 0;

    int g;

    for (int i = 0; i < n; ++i){
        cin >> value[i];

        g = i == 0 ? value[i] : __gcd(g, value[i]);

        if (value[i] == 1)
            one++;
    }

    if (one){
        cout << n - one << endl;
        return 0;
    }

    if (g > 1){
        cout << -1 << endl;
        return 0;
    }

    int answer = 3 * n;

    for (int i = 0; i < n; ++i){
        int g = value[i];

        for (int j = i + 1; j < n; ++j){
            g = __gcd(g, value[j]);

            if (g == 1){
                answer = min(answer, n - 1 + j - i);
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
}