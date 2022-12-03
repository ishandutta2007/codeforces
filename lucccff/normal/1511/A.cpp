#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        l=0;
        for(j=0;j<n;j++) {
            cin>>k;
            if (k!=2) l++;
        }
        cout<<l<<endl;
    }
    return 0;
}