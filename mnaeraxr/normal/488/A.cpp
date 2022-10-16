#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)1e5 + 10;

bool is_lucky(int n){
    n = abs(n);
    while (n){
        if (n % 10 == 8) return true;
        n /= 10;
    }
    return false;
}

int main()
{
    int n; cin >> n;
    int ans = 1;
    ++n;
    while (!is_lucky(n)){
        ++n, ++ans;
    }
    cout << ans << endl;
}