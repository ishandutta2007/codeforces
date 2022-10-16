#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

bool is_prime(int n){
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int m = n;

    while (!is_prime(m))
        m++;

    cout << m << endl;
    for (int i = 1; i < n; ++i){
        cout << i << " " << i + 1 << endl;
    }
    cout << n << " " << 1 << endl;

    int j = n / 2;
    int e = m - n;

    for (int i = 1; i <= e; ++i){
        cout << i << " " << i + j << endl;
    }

    // for (int i = 3; i <= 1000; ++i){
    //     bool ok = false;

    //     for (int j = i; j <= i + i / 2; ++j){
    //         if (is_prime(j)){
    //             ok = true;
    //             break;
    //         }
    //     }

    //     if (!ok)
    //     cout << i << " " << ok << endl;
    // }

    return 0;
}