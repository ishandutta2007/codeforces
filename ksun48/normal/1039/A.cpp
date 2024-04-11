#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    int n;
    LL t;
    cin >> n >> t;
    vector<LL> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] += t;
    }
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
        x[i]--;
        if(x[i] < i){
            cout << "No" << '\n';
            return 0;
        }
    }
    vector<int> no(n-1, 0);
    set<int> noset;
    noset.insert(n);
    for(int i = 0; i < n; i++){
        if(x[i] < n-1) no[x[i]] = 1;
    }
    for(int i = 0; i < n-1; i++){
        if(no[i]) noset.insert(i);
    }
    for(int i = 0; i < n; i++){
        int f = *noset.lower_bound(i);
        if(f < x[i]){
            cout << "No" << '\n';
            return 0;
        }
    }
    vector<LL> b(n);
    for(int i = 0; i < n; i++){
        b[i] = a[i];
        if(i > 0) b[i] = max(b[i], b[i-1] + 1);
        if(i < n-1){
            if(no[i]){
                if(b[i] >= a[i+1]){
                    cout << "No" << '\n';
                    return 0;
                }
            } else {
                b[i] = max(b[i], a[i+1]);
            }
        }
    }
    cout << "Yes" << '\n';
    for(int i = 0; i < n; i++){
        cout << b[i] << ' ';
    }
    cout << '\n';
}