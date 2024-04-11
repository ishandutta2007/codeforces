#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k = n;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]){
            k--;
        }
    }
    cout << k << endl;
    return 0;
}