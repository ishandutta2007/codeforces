#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int t;
    cin >> t;
    int m = 0;
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(a[j] - a[i] > t){
                m = max(m,j-i);
                break;
            }
            if(j == n-1){
                m = max(m, n-i);
            }
        }
    }
    cout << m << endl;
    return 0;
}