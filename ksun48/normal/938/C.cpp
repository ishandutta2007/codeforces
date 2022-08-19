#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL q;
    cin >> q;
    for(int i = 0; i < q; i++){
        LL x;
        cin >> x;
        if(x == 0){
            cout << 1 << " " << 1 << endl;
            continue;
        }
        vector<LL> a, b;
        for(LL d = 1; d*d <= x; d++){
            if(x % d != 0) continue;
            a.push_back(d);
            b.push_back(x/d);
        }
        int found = 0;
        for(int j = 0; j < a.size(); j++){
            if((a[j] + b[j]) % 2 == 1) continue;
            int n = (a[j] + b[j])/2;
            int d = (b[j] - a[j])/2;
            if(d == 0) continue;
            int q = n/d;
            if(n/q == d){
                found = 1;
                cout << n << " " << q << endl;
                break;
            }
        }
        if(!found){
            cout << -1 << endl;
        }
    }
}