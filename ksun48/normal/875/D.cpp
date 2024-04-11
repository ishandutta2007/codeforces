#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


LL n;
LL a[210000];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    LL ans = n*(n+1)/2;
    LL lidx[n];
    LL ridx[n];
    for(int i = 0; i < n; i++){
        lidx[i] = 0;
        ridx[i] = n-1;
    }
    map<LL,LL> nextval;
    for(int i = 0; i < n; i++){
        if(nextval.find(a[i]) != nextval.end()) lidx[i] = max(lidx[i], nextval[a[i]] + 1);
        nextval[a[i]] = i;
    }

    for(LL c = 0; c < 33; c++){
        LL d = (1LL << c);
        LL last1 = -1;
        for(int i = 0; i < n; i++){
            if(a[i] & d){
                last1 = i;
                continue;
            }
            lidx[i] = max(lidx[i], last1+1);
        }
    }
    for(LL c = 0; c < 33; c++){
        LL d = (1LL << c);
        LL last1 = n;
        for(int i = n-1; i >= 0; i--){
            if(a[i] & d){
                last1 = i;
                continue;
            }
            ridx[i] = min(ridx[i], last1-1);
        }
    }

    for(LL i = 0; i < n; i++){
        //cout << lidx[i] << " " << ridx[i] << endl;
        ans -= (i - lidx[i] + 1) * (ridx[i] - i + 1);
    }
    cout << ans << endl;


}