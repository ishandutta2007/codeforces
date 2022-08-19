#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

typedef bitset<710> B;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool okl[n][n]; // flip
    bool okr[n][n];
    bool g[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            g[i][j] = (__gcd(a[i], a[j]) > 1);
        }
    }
    for(int j = n-1; j >= 0; j--){
        for(int k = j; k < n; k++){
            okl[k][j] = okr[j][k] = 0;
            if(j == k){
                okl[k][j] = okr[j][k] = 1;
            } else {
                okl[k][j] = okr[j][k] = 0;
                for(int s = j; s <= k-1; s++){
                    if(g[k][s] && okr[j][s] && okl[k-1][s]){
                        okr[j][k] = 1;
                    }
                }
                for(int s = j + 1; s <= k; s++){
                    if(g[j][s] && okr[j+1][s] && okl[k][s]){
                        okl[k][j] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int s = 0; s < n; s++){
        if(okr[0][s] && okl[n-1][s]){
            ans = 1;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}