#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,a,b;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>a>>b;
        if (a==b) {
            cout<<0<<endl;
            continue;
        }
        else if (a<b) {
            a+=b;
            b=a-b;
            a-=b;
        }
        k=(a-b)/5;
        l=(a-b)%5;
        if (l>0) k++;
        if (l>2) k++;
        cout<<k<<endl;
    }
    return 0;
}