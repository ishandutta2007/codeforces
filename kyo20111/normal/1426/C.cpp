#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n;
        int k = sqrt(n);
        cout << (k-1) + ((n / k) - 1) + (!!(n % k)) << "\n";
    }
}