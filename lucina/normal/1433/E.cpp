#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int64_t c(int x, int y) {
    int64_t ans = 1;
    for (int i = 1 ; i <= x ; ++ i)
        ans *= i;
    for (int i = 1 ; i <= y ; ++ i) {
        ans /= i;
    }

    for (int i = 1 ; i <= x - y ; ++ i) {
        ans /= i;
    }

    return ans;
}

int64_t fac(int bar) {
    int ans = 1;
    for (int i = 1 ; i <= bar; ++ i)
        ans *= i;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    cout << (c(n, n / 2) / 2)  * fac(n / 2 - 1) * fac(n / 2 - 1)<< '\n';
}