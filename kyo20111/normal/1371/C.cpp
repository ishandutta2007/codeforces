#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int tc;
ll v, c, n, m;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> v >> c >> m >> n;
        if(v + c < n + m){
            cout << "No\n";
            continue;
        }

        if(m > n){
            ll k = m - n;

            if(v - k >= c){
                v -= k;
            }else if(c - k >= v + 1){
                c -= k;
            }else{
                ll sum = (v + c - k) / 2;
                v = c = sum;
                if((v + c - k) % 2) v += 1;
            }

            m = n;
        }

        ll k = min(n, m);
        v -= k, c -= k;
        n -= k, m -= k;

        if(v > c) c -= n;
        else v -= n;

        if(c >= 0 && v >= 0){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}