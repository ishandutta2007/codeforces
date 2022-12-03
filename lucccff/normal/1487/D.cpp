#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        k=sqrt(n*2-1);
        cout<<(k-1)/2<<endl;
    }
    return 0;
}