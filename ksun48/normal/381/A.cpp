#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int d = 0;
    int e = 0;
    int l = 0;
    int r = n-1;
    int k = 1;
    while(k <= n){
        if(a[l] > a[r]){
            if(k % 2) d+= a[l];
            if(!(k%2)) e+= a[l];
            l++;
        } else {
            if(k % 2) d+= a[r];
            if(!(k%2)) e+= a[r];
            r--;
        }
        k++;
    }
    cout << d << " " << e << endl;
    return 0;
}