#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i, a[105];
    cin >> n; 
    for (i = 0; i<n; ++i){ 
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = 0; i<n; ++i) 
        cout << a[i] << " ";
    return 0; 
}
//double click