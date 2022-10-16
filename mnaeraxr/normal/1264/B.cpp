#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

void no(){
    cout << "NO" << endl;
    exit(0);
}

void yes() {
    cout << "YES" << endl;
}

void num(int a){
    cout << a << " ";
}

void seq(int a, int b, int t) {
    for (int i = 0; i < t; ++i)
        cout << a << " " << b << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    if (a > b + 1) no();
    if (d > c + 1) no();
    if (a == b + 1 && c + d > 0) no();
    if (d == c + 1 && a + b > 0) no();

    if (a == b + 1) {
        yes();
        num(0);
        seq(1, 0, b);
        return 0;
    }

    if (d == c + 1) {
        yes();
        num(3);
        seq(2, 3, c);
        return 0;
    }

    b -= a;
    c -= d;

    if (abs(b - c) > 1) no();

    yes();

    if (b > c) num(1);
    seq(0, 1, a);
    seq(2, 1, min(b, c));
    seq(2, 3, d);
    if (c > b) num(2);

    return 0;
}