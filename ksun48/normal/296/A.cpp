#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int b[10000];
    int maxi = 0, a;
    for(int i = 0; i < 10000; i++) b[i] = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        maxi=max(maxi,++b[a]);
    }
    if(maxi <= ((n+1)/2)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}