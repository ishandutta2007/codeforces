#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    int n;
    cin >> n;
    LL g = -1;
    LL a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(g == -1){
            g = a * b;
        } else {
            g = __gcd(g, a * b);
        }
    }
    if(g == 1){
        cout << -1 << endl;
    } else {
        LL num;
        if(__gcd(a,g) > 1){
            num = __gcd(a,g);
        } else if(__gcd(b,g) > 1){
            num = __gcd(b,g);
        } else {
            assert(0);
        }
        for(int p = 2; p * p <= num; p++){
            if(num % p == 0){
                cout << p << endl;
                return 0;
            }
        }
        cout << num << endl;
        return 0;
    }
}