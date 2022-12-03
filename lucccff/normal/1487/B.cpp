#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        if (n%2==0) {
            cout<<(k-1)%n+1<<endl;
        }
        else {
            l=n/2;
            l=(k-1)/l+k;
            cout<<(l-1)%n+1<<endl;
        }
    }
    return 0;
}