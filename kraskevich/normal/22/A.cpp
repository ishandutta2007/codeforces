#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int a[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
            
    sort(a, a + n);
    
    int j = 1;
    while(j < n && a[j] == a[j - 1])
            ++j;
    
    if(j == n) 
         cout << "NO";
    else
        cout << a[j];
    
    cin >> n;
    
    return 0;
}