#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if(n <= 2) return cout << -1 << endl,0;
    if(n%2 == 0){
        n = n * n;
         n >>= 2;
         return cout << n - 1 <<' '<< n + 1 << endl,0;
    }
    n = n * n;
    n >>= 1;
    cout << n << ' '<< n + 1 << endl;
}