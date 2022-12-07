#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int n; cin >> n;
    vector<string> bus(n);

    bool l = true;

    for (int i = 0; i < n; ++i){
        cin >> bus[i];

        if (l){
            if (bus[i][0] == 'O' && bus[i][1] == 'O'){
                bus[i][0] = '+', bus[i][1] = '+';
                l = false;
            }

            if (l && bus[i][3] == 'O' && bus[i][4] == 'O'){
                bus[i][3] = '+', bus[i][4] = '+';
                l = false;
            }
        }
    }

    if (l) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
            cout << bus[i] << endl;
    }

    return 0;
}