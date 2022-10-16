#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 a, b, c;

    cin >> a >> b >> c;

    int64 ga = __gcd(a, c);
    int64 la = a / ga;
    c /= ga;

    int64 gb = __gcd(b, c);
    int64 lb = b / gb;
    c /= gb;

    if (c % 2 == 0){
        c /= 2;
    }
    else{
        if (la * 2 <= a)
            la *= 2;
        else if (lb * 2 <= b)
            lb *= 2;
        else{
            cout << "NO" << endl;
            exit(0);
        }
    }

    if (c > 1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << 0 << " " << 0 << endl;
        cout << la << " " << 0 << endl;
        cout << 0 << " " << lb << endl;
    }
}