#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n, k;
    cin >> n >> k;
    if(k == 1){
        cout << n << endl;
        return 0;
    }
    LL f = 1;
    while(f < n) f = 2*f+1;
    cout << f << endl;
}