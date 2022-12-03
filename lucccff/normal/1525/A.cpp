#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
    if (a<b) {
        a+=b;
        b=a-b;
        a-=b;
    }
    int r=a%b;
    while(r>0) {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main(){
    int i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>k;
        l=gcd(k,100);
        cout<<100/l<<endl;
    }
    return 0;
}