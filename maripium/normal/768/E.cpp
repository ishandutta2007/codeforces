#include<bits/stdc++.h>
using namespace std;

const int grd[] = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

int main() {
    int n;
    scanf("%d",&n);
    int res = 0;
    for(int i = 0;i < n;++i) {
        int x; cin >> x;
        res ^= grd[x - 1];
    }
    cout << (res ? "NO" : "YES") << endl;
}