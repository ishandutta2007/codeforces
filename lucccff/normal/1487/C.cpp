#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++){
            for(k=j+1;k<n;k++){
                if ((k-j)*2<n) {
                    cout<<1;
                }
                else if ((k-j)*2>n) {
                    cout<<-1;
                }
                else {
                    cout<<0;
                }
                cout<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}