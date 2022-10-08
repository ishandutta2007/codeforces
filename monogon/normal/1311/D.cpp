
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, a, b, c;

int solve(int a, int b) {
    int B = max(b, a);
    int B1 = B / a * a, B2 = (B + a - 1) / a * a;
    if(abs(B1 - b) < abs(B2 - b)) {
        return B1;
    }else return B2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        int cost = 1e5;
        int a2 = 0, b2 = 0, c2 = 0;
        for(int B = 1; B <= 2e4; B++) {
            int C = solve(B, c);
            int A = B;
            for(int k = 1; k * k <= B; k++) {
                if(B % k == 0) {
                    if(abs(k - a) < abs(A - a)) A = k;
                    if(abs(B / k - a) < abs(A - a)) A = B / k;
                }
            }
            int cst = abs(a - A) + abs(b - B) + abs(c - C);
            if(cst < cost) {
                cost = cst;
                a2 = A;
                b2 = B;
                c2 = C;
            }
        }
        cout << cost << endl;
        cout << a2 << " " << b2 << " " << c2 << endl;
    }
}