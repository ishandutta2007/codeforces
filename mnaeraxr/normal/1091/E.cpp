#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

void fin(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n; cin >> n;

    vector<int64> g(n);

    int64 p = 0;

    int64 SC = 0, SA = 0;
    int64 A = 0, B = n, C = 0;

    for (int i = 0; i < n; ++i){
        cin >> g[i];

        p ^= g[i] & 1;
    }

    int64 a = 0, b = n;

    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());

    for (int64 k = 1, j = n - 1; k <= n; ++k){
        while (g[j] <= k && j >= k){
            B--;
            C++;
            SC += g[j];
            j--;
        }

        SA += g[k - 1];

        if (B > 0){
            B--;
        }
        else{
            C--;
            SC -= g[k - 1];
        }

        A = k;

        int64 T = k * (k - 1 + B) + SC - SA + A;

        if (T < 0){
            fin();
        }

        int64 mid = A;
        int64 sub = min(A, T);

        int64 add = B + min(T, C);
        // cout << k << ": " << A << " " << B << " " << C << endl;
        // cout << k << ": " << SA << " " << SC << " " << T << endl;
        // cout << sub << " " << mid << " " << add << endl;
        // cout << mid - sub << " " << mid + add << endl;
        // cout << endl;

        a = max(a, mid - sub);
        b = min(b, mid + add);
    }


    if (p != (a & 1))
        a++;

    if (p != (b & 1))
        b--;

    if (a > b){
        cout << -1 << endl;
    }
    else{
        for (int64 i = a; i <= b; i += 2){
            cout << i << " ";
        }
    }

    return 0;
}