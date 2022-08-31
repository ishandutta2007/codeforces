#include <iostream>
using namespace std;

int main() {
    int c1, c2, c3, c4, n, m;
    cin >> c1 >> c2 >> c3 >> c4 >> n >> m;
    int a[n];
    int b[m];
    int asum = 0;
    int bsum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= c1;
        asum += min(c2,a[i]);
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        b[i] *= c1;
        bsum += min(c2,b[i]);
    }
    cout << min(c4,min(asum,c3)+min(bsum,c3)) << endl;

    return 0;
}