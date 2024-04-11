#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<LL> b(n);
    int nonzero = 0;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(b[i] > 0) nonzero = 1;
    }
    if(nonzero == 0){
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++){
            cout << 2 << ' ';
        }
        cout << endl;
        return 0;
    }
    int allequal = 1;
    for(int i = 0; i < n; i++){
        if(b[i] != b[(i+1) % n]) allequal = 0;
    }
    if(allequal){
        cout << "NO" << '\n';
        return 0;
    }
    vector<LL> a(n);
    for(int i = 0; i < n; i++){
        if(b[(i+n-1) % n] < b[i]){
            LL cur = b[i];
            a[i] = cur;
            for(int j = 1; j < n; j++){
                int idx = (i - j + n) % n;
                if(cur < 100000000LL){
                    LL g = (100000000LL / cur) + 1;
                    cur *= g;
                }
                cur += b[idx];
                a[idx] = cur;
            }
            break;
        }
    }
    cout << "YES" << '\n';
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << '\n';
}