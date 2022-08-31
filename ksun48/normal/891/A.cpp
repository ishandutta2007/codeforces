#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    int a[n];
    int non1 = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] != 1) non1++;
    }
    int g = a[0];
    for(int i = 0; i < n; i++){
        g = __gcd(g, a[i]);
    }
    if(g > 1){
        cout << -1 << endl;
        return 0;
    }
    if(non1 < n){
        cout << non1 << endl;
        return 0;
    }

    int minlen = n;

    for(int i = 0; i < n; i++){
        int v = a[i];
        for(int j = i; j < n; j++){
            v = __gcd(v, a[j]);
            if(v == 1){
                minlen = min(minlen, j-i+1);
                break;
            }
        }
    }
    cout << minlen-1 + n-1 << endl;
}