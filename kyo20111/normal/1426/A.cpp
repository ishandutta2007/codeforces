#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n, m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        int c = 1;
        if(n <= 2){
            cout << c << "\n";
            continue;
        }
        n -= 2;
        while(n > m) n -= m, c++;
        cout << c + 1 << "\n";
    }
}