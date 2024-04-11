#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n, k;
    cin >> n >> k;
    LL maxv = (k-1) / 2;
    LL minv = 1;
    maxv = min(maxv, n);
    minv = max(minv, k-n);
    if(minv > maxv){
        cout << 0 << endl;
    } else {
        cout << maxv - minv + 1 << endl;
    }
}