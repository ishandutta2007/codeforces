#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n+1];
    for(int i = 0; i <= n; i++) a[i] = 0;
    for(int i = 0; i < m; i++){
        int b,c,d;
        cin >> b >> c >> d;
        if(a[c]) swap(b,c);
        if(a[d]) swap(b,d);
        if(a[b] == 0){
            a[b] = 1;
            a[c] = 2;
            a[d] = 3;
        } else {
            a[c] = (a[b])%3+1;
            a[d] = (a[b]+1)%3+1;
        }
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}