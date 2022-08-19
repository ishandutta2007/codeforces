#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> ll[2];
    vector<int> rr[2];
    for(int j = 0; j < n; j++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll[0].push_back(x1);
        rr[0].push_back(x2);
        ll[1].push_back(y1);
        rr[1].push_back(y2);
    }
    vector<int> ok(n, 1);
    vector<int> x(n, 0);
    vector<int> y(n, 0);
    for(int q = 0; q < 2; q++){
        vector<int> minr_left(n), minr_right(n), maxl_left(n), maxl_right(n);
        vector<int> l = ll[q];
        vector<int> r = rr[q];
        for(int i = 0; i < n; i++){
            maxl_left[i] = maxl_right[i] = l[i];
            minr_left[i] = minr_right[i] = r[i];
        }
        for(int i = 1; i < n; i++){
            minr_left[i] = min(minr_left[i], minr_left[i-1]);
            maxl_left[i] = max(maxl_left[i], maxl_left[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
            minr_right[i] = min(minr_right[i], minr_right[i+1]);
            maxl_right[i] = max(maxl_right[i], maxl_right[i+1]);
        }
        for(int i = 0; i < n; i++){
            int minr =  1500000000;
            int maxl = -1500000000;
            if(i > 0){
                maxl = max(maxl, maxl_left[i-1]);
                minr = min(minr, minr_left[i-1]);
            }
            if(i + 1 < n){
                maxl = max(maxl, maxl_right[i+1]);
                minr = min(minr, minr_right[i+1]);
            }
            if(maxl > minr){
                ok[i] = 0;
            } else {
                if(q == 0) x[i] = maxl;
                if(q == 1) y[i] = maxl;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(ok[i]){
            cout << x[i] << " " << y[i] << endl;
            break;
        }
    }
}