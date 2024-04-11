#include <iostream>
using namespace std;

int main() {
int n;
cin >> n;
int a[n];
int b[n];
int asum = 0;
int bsum = 0;
for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
    asum += a[i];
    bsum += b[i];
}
if(asum % 2 == 0 && bsum % 2 == 0){
    cout << 0 << endl;
} else if(asum % 2 == 1 && bsum % 2 == 1){
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != b[i] % 2){
            cout << 1 << endl;
            return 0;
        }}
        cout << -1 << endl;
        return 0;

} else {
    cout << -1 << endl;
}
    return 0;
}