#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,max,min;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        cin>>max>>min;
        for(j=1;j<n;j++) {
            cin>>k>>l;
            if (k>max) max=k;
            if (l<min) min=l;
        }
        if (max<min) cout<<0<<endl;
        else cout<<max-min<<endl;
    }
    return 0;
}