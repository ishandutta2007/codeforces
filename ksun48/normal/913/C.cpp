#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n, L;
    cin >> n >> L;
    LL c[n];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = n-1; i > 0; i--){
        c[i-1] = min(c[i-1], c[i]);
    }
    for(int i = 1; i < n; i++){
        c[i] = min(c[i], c[i-1]*2);
    }

    LL need = (L >> (n-1) );
    L -= need << (n-1);
    need *= c[n-1];

    LL best = 0;
    for(int j = 0; j < n; j++){
        if(L & (1<<j)) best += c[j];
    }
    for(int i = 0; i < n; i++){
        LL cur = c[i];
        for(int j = i; j < n; j++){
            if(L & (1<<j)) cur += c[j];
        }
        best = min(best, cur);
    }
    cout << best + need << endl;
}