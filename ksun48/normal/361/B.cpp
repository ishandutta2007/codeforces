#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if(n == k){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= n-k; i++){
        cout << i % (n-k)+1 << " ";
    }
    for(int i = n-k+1; i <= n; i++){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}