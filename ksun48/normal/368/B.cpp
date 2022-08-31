#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    set<int> q;
    int b[n];
    for(int i = n-1; i >= 0; i--){
        q.insert(a[i]);
        b[i] = q.size();
    }
    for(int i = 0; i < m; i++){
        int r;
        cin >> r;
        cout << b[r-1] << endl;
    }
    return 0;
}