#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int n;
    cin >> n;
    int a[8];
    for(int i = 0; i < 8; i++){
        a[i] = 0;
    }
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        a[k]++;
    }
    if(a[5] > 0 || a[7] > 0){
        cout << -1 << endl;
        return 0;
    }
    if(a[1] < a[4] || a[2] < a[4]){
        cout << -1 << endl;
        return 0;
    }
    a[1] -= a[4];
    a[2] -= a[4];
    if(a[1] < a[2] || a[6] < a[2]){
        cout << -1 << endl;     
        return 0;
    }
    a[1] -= a[2];
    a[6] -= a[2];
    if(a[1] != a[3] || a[1] != a[6]){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < a[4]; i++){
        cout << "1 2 4" << endl;
    }
    for(int i = 0; i < a[2]; i++){
        cout << "1 2 6" << endl;
    }
    for(int i = 0; i < a[1]; i++){
        cout << "1 3 6" << endl;
    }

    return 0;
}