#include <bits/stdc++.h>
typedef long long i64;
using namespace std;
const int N = 1e5 + 10;
int n, b, e;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int full = (1 << 10) - 1;
    for(int i = 1; i <= n; i++) {
        char opt;
        int x;
        cin >> opt >> x;
        if(opt == '|') {
            b |= x;
            e |= x;
        } else if(opt == '&') {
            b &= x;
            e |= (full ^ x);
        } else {
            b ^= x;
        }
    }
    int Xor = b ^ (b & e);
    int Or = b & e;
    int And = full ^ ((full ^ b) & e);
    cout << 3 << endl;
    cout << "^ " << Xor << endl;
    cout << "| " << Or << endl;
    cout << "& " << And << endl;
    return 0;
}