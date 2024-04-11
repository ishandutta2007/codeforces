#include <iostream>
using namespace std;

int main() { 
    int n;
    cin >> n;
    
    int mx = 0;
    int sum = 0;
    for( int i= 0 ; i < n ; i++ ) { 
        int a,b;
        cin >> a >> b;
        sum = sum - a + b;
        mx = max( mx , sum ) ; 
    }
    cout << mx << endl;
}