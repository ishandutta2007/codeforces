#include <iostream>
using namespace std;
typedef long long LL;

int main() {
    LL n, k;
    cin >> n >> k;
    if(k <= ((n+1)/2)){
        cout << 2*k-1 << endl;
    } else {
        LL r = (n+1)/2;
        cout << 2*(k-r) << endl;
    }
    return 0;
}