#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n, a, b;
    cin >> n >> a >> b;
    if(a < b) swap(a,b);
    for(LL c = 0; c * a <= n; c++){
        LL d = (n - c * a) / b;
        if(a * c + b * d != n) continue;
        int cur = 1;
        for(int j = 0; j < c; j++){
            for(int r = 1; r <= a; r++){
                cout << cur + (r % a) << " ";
            }
            cur += a;
        }
        for(int j = 0; j < d; j++){
            for(int r = 1; r <= b; r++){
                cout << cur + (r % b) << " ";
            }
            cur += b;
        }
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}