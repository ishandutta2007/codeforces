#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int p;
    cin >> p;
    double ans = 0;
    LL numways[60][3000];
    for(int j = 0; j < 60; j++){
        for(int k = 0; k < 3000; k++){
            numways[j][k] = 0;
        }
    }
    numways[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int c = 50; c >= 0; c--){
            for(int j = 0; j <= 2500; j++){
                numways[c+1][j + a[i]] += numways[c][j];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        LL total = 0;
        LL works = 0;
        for(int j = 0; j <= 2500; j++){
            total += numways[i][j];
            if(j <= p) works += numways[i][j];
        }
        ans += (double)(works)/(double)(total);
    }
    cout << ans << endl;
}