#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int a1,a2,k1,k2,n;

int main(){
    cin>>a1>>a2>>k1>>k2>>n;
    int mi = 0, ma = 0;
    int c = n;
    c -= (k1-1)*a1;
    c -= (k2-1)*a2;
    if(c <= 0){
        mi = 0;
    }
    else{
        mi = min(a1+a2,c);
    }
    if(k1 <= k2){
        ma += min(a1,n/k1);
        n -= (k1) * min(a1,n/k1);
        ma += min(a2,n/k2);
    }
    else{
        ma += min(a2,n/k2);
        n -= (k2) * min(a2,n/k2);
        ma += min(a1, n / k1);
    }
    printf("%d %d\n",mi,ma);
}
/*
    Good Luck
        -Lucina
*/