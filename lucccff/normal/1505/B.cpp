#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,a;
    cin>>a;
    k=0;
    for(i=0;i<4;i++) {
        k=0;
        while(a!=0) {
            k+=a%10;
            a/=10;
        }
        a=k;
    }
    cout<<k;
    return 0;
}