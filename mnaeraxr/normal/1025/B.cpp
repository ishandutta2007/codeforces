#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

void primes(int x, set<int> &p){
    for (int i = 2; i * i <= x; ++i){
        while (x % i == 0){
            p.insert(i);
            x /= i;
        }
    }

    if (x > 1)
        p.insert(x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> A(n), B(n);

    for (int i = 0; i < n; ++i){
        cin >> A[i] >> B[i];
    }

    set<int> p;
    primes(A[0], p);
    primes(B[0], p);

    for (auto pr : p){
        bool ok = true;

        for (int i = 0; i < n && ok; ++i){
            ok &= (A[i] % pr == 0) | (B[i] % pr == 0);
        }

        if (ok){
            cout << pr << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}