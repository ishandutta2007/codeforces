#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n+1];
    set<int> idk;
    for(int i = 0; i < n; i++){
        idk.insert(i+1);
        a[i+1] = 0;
    }
    for(int i = 0; i < m; i++){
        int l, r, w;
        cin >> l >> r >> w;
        while(1){
            if(idk.lower_bound(l) == idk.end()) break;
            int k = *idk.lower_bound(l);
            if(k > r){
                break;
            }
            if(k != w) a[k] = w;
            idk.erase(idk.lower_bound(l));
        }
        idk.insert(w);
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}