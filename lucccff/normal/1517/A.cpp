#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        if (n%2050!=0) cout<<-1; 
        else {
            k=0;
            n=n/2050;
            while(n!=0) {
                k+=n%10;
                n=n/10;
            }
            cout<<k;
        }
        cout<<endl;
    }
    return 0;
}