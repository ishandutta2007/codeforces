#include <iostream>
using namespace std;
#include <algorithm>
int main() {
    int n,m;
    cin >> n >> m;
    int a[m];
    for(int i = 0; i <= m; i++){
        cin >> a[i];
    }
    sort(a, a+m);
    int m1 = 100000;
    for(int i = 0; i + n-1 < m; i++){
        m1 = min(a[i+n-1]-a[i], m1);
    }
    cout << m1 << endl;
    return 0;
}