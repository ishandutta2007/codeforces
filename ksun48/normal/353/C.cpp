#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i< n; i++) cin >> a[i];
    char k[n+1];
    cin >> k;
    int sums[n+1];
    sums[0] = 0;
    for(int i = 1; i <=n; i++){
        sums[i] = sums[i-1]+a[i-1];
    }
    int cur = 0;
    int mans = 0;
    for(int i = n-1; i >= 0; i--){
        if(k[i] == '1'){
            mans = max(mans, cur+sums[i]);
            cur += a[i];
        }
        mans = max(mans, cur);
    }
    cout << mans << endl;
    return 0;
}